#pragma once

#include <cstdint>
#include <string_view>

namespace XRechnungUtils {
    // https://www.xrepository.de/details/urn:xoev-de:kosit:codeliste:currency-codes_3
    enum class ISO4217_CurrencyCode {
        Unknown = 0,
        Swiss_Franc = 756,
        British_Pfund = 826,
        US_Dollar = 840,
        Euro = 978
    };

    constexpr std::u8string_view ISO4217_toStdStringView(const ISO4217_CurrencyCode currencyCode) noexcept {
        switch (currencyCode) {
            case ISO4217_CurrencyCode::Swiss_Franc:
                return u8"CHF";
            case ISO4217_CurrencyCode::British_Pfund:
                return u8"GBP";
            case ISO4217_CurrencyCode::US_Dollar:
                return u8"USD";
            case ISO4217_CurrencyCode::Euro:
                return u8"EUR";
            case ISO4217_CurrencyCode::Unknown:
                return {};
        }

        return {};
    }
}// namespace XRechnungUtils
