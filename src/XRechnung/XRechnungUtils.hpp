#pragma once

#include <array>

namespace XRechnungUtils {
    // Converts an std::string (codepage encoding) to UTF-8 string
    inline std::u8string stdStringToU8Str(const std::string &str) {
        return {reinterpret_cast<const char8_t *>(str.data()), str.size()};
    }

    template<typename T>
        requires std::is_same_v<T, std::u8string> ||
                 std::is_same_v<T, std::u8string_view>
    std::string u8StrToStdStr(const T &u8str) {
        return {reinterpret_cast<const char *>(u8str.data())};
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
                    u8"S", u8"Z", u8"E", u8"AE", u8"K", u8"G", u8"O", u8"L", u8"M"};
}// namespace XRechnungUtils
