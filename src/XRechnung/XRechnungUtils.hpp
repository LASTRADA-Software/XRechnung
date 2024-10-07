#pragma once

#include <array>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>

#if defined(_WIN32) || defined(_WIN64)
#include <map>
#include <windows.h>
#endif

namespace XRechnungUtils {
    // Converts an std::string (codepage encoding) to UTF-8 string
    inline std::u8string stdStringToU8Str(const std::string& str)
    {
        // no need for conversion
        if (str.empty())
            return {};

#if defined(_WIN32) || defined(_WIN64)
        // Converts from codepage encoding to UTF-8 via UTF-16 encoding.

        auto const EnsureSuccess = [](int result)
        {
            if (result != 0)
                return;

            switch (GetLastError())
            {
                case ERROR_INSUFFICIENT_BUFFER:
                    throw std::runtime_error("Insufficient buffer");
                case ERROR_NO_UNICODE_TRANSLATION:
                    throw std::invalid_argument("No Unicode translation");
                case ERROR_INVALID_FLAGS:
                case ERROR_INVALID_PARAMETER:
                default:
                    throw std::runtime_error("Internal error during UTF-8 conversion");
            }
        };

        // compute length of the target UTF-16 string
        auto const utf16SizeNeeded = MultiByteToWideChar(GetACP(), 0, str.data(), str.size(), nullptr, 0);

        // Preallocate the target string
        std::wstring utf16(utf16SizeNeeded, 0);

        // Convert the source string to UTF-16
        EnsureSuccess(MultiByteToWideChar(GetACP(), 0, str.data(), str.size(), utf16.data(), utf16SizeNeeded));

        // compute length of the target UTF-8 string
        auto const utf8SizeNeeded = WideCharToMultiByte(CP_UTF8, 0, utf16.data(), utf16.size(), nullptr, 0, nullptr, nullptr);

        // Preallocate the target string
        std::u8string utf8(utf8SizeNeeded, 0);

        // Convert the UTF-16 string to UTF-8
        EnsureSuccess(WideCharToMultiByte(CP_UTF8, 0, utf16.data(), utf16.size(), reinterpret_cast<char*>(utf8.data()), utf8SizeNeeded, nullptr, nullptr));

        return utf8;
#else
        // TODO
        return { reinterpret_cast<const char8_t*>(str.data()), str.size() };
#endif
    }

    template<typename T>
        requires std::is_same_v<T, std::u8string> ||
                 std::is_same_v<T, std::u8string_view>
    std::string u8StrToStdStr(const T& u8str) {
        return { reinterpret_cast<const char*>(u8str.data()) };
    }

    // UNTDID 1001
    // https://www.xrepository.de/details/urn:xoev-de:kosit:codeliste:untdid.1001_4
    enum class InvoiceType : uint16_t {
        Undefined = 0,
        Partial = 326,
        Commercial = 380,
        Corrected = 384,
        SelfBilled = 389,
        CreditNote = 381,
        PartialConstruction = 875,
        PartialFinalConstruction = 876,
        FinalConstruction = 877
    };

    enum class PointDateCode : uint16_t {
        Undefined = 0,
        InvoiceDocumentIssueDateTime = 3,
        DeliveryDateTime = 35,
        PaidToDate = 432
    };

    enum class VATCategory : int16_t {
        Unknown = -1,
        StandardRate = 0,
        ZeroRatedGoods,
        ExemptFromTax,
        VATReverseCharge,
        VATExemptFromEEA,
        FreeExport,
        ServicesOutsideTaxScope,
        CanaryIslandIndirectTax,
        CeutaMelillaTax
    };

    static constexpr std::array<std::u8string_view, 9>
            allowedCodes{
                    u8"S", u8"Z", u8"E", u8"AE", u8"K", u8"G", u8"O", u8"L", u8"M" };

    static const std::map<char, std::string> escapeChar {
            {'<', "&lt;"},
            {'>', "&gt;"},
            {'&', "&amp;"},
            {'"', "&quot;"},
            {'\'', "&apos;"},
    };

    inline std::string escapeSpecialChars(const std::string &txt) {
        if (txt.empty())
            return txt;

        std::string res{};
        for (const auto chr : txt) {
            if (escapeChar.contains(chr)) {
                res += escapeChar.at(chr);
            }
            else {
                res.push_back(chr);
            }
        }

        return res;
    }
};// namespace XRechnungUtils