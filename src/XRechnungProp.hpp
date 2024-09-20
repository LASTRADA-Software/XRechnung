#pragma once
#include "XRechnungMapping.hpp"

#include <cstddef>
#include <optional>
#include <sstream>
#include <string>
#include <vector>


namespace XRechnungUtils {
    enum class ISO4217_CurrencyCode;
    enum class VATCategory : int16_t;
    enum class EASCode : uint16_t;
    enum class MEASURE_UNIT : uint16_t;
    enum class AllowanceChargeCode;
}// namespace XRechnungUtils

namespace XRechnung {
    using namespace std::string_literals;

    struct EnitityBaseProp {
        std::u8string name{};
        std::optional<std::u8string> tradingName{std::nullopt};
        std::optional<std::u8string> vatIdentifier{std::nullopt};
    };

    struct BuyerProp {
        std::optional<std::u8string> name{};
        std::optional<std::u8string> tradingName{std::nullopt};
        std::optional<std::u8string> identifier{std::nullopt};
        std::optional<std::u8string> legalRegistrationId{std::nullopt};
        std::optional<std::u8string> vatIdentifier{std::nullopt};
    };

    struct SellerProp : EnitityBaseProp {
        std::optional<std::u8string> legalIdentifier{std::nullopt};
        std::optional<std::u8string> taxRegistrationIdentifier{std::nullopt};
        std::optional<std::u8string> additionalLegalInformation{std::nullopt};
    };

    struct EntityAddress {
        std::optional<std::u8string> addressLine1{std::nullopt};
        std::optional<std::u8string> addressLine2{std::nullopt};
        std::optional<std::u8string> addressLine3{std::nullopt};

        std::u8string city{};
        std::u8string postalCode{};

        std::optional<std::u8string> countrySubentity{std::nullopt};
        std::u8string countryCode{};
    };

    struct Period {
        std::optional<std::u8string> startDate{};
        std::optional<std::u8string> endDate{};
    };

    struct BaseProp {
        bool chargeIndicator{false};
        double amount{};
        XRechnungUtils::AllowanceChargeCode reasonCode{};
        std::optional<double> baseAmount{std::nullopt};
        std::optional<double> percentage{std::nullopt};
        std::optional<std::u8string> reason{std::nullopt};
    };

    struct BaseVATProp {
        XRechnungUtils::VATCategory VATCategoryCode{};
        double VATPercentage{};
    };

    struct ChargeProp {
        bool chargeIndicator{false};
        double amount{};
        XRechnungUtils::AllowanceChargeCode reasonCode{};
        std::optional<double> baseAmount{std::nullopt};
        std::optional<double> percentage{std::nullopt};
        std::optional<std::u8string> reason{std::nullopt};
    };

    struct VATChargeProp {
        bool chargeIndicator{false};
        double amount{};
        XRechnungUtils::AllowanceChargeCode reasonCode{};
        std::optional<double> baseAmount{std::nullopt};
        std::optional<double> percentage{std::nullopt};
        std::optional<std::u8string> reason{std::nullopt};
        XRechnungUtils::VATCategory VATCategoryCode{};
        double VATPercentage{};
        XRechnungUtils::ISO4217_CurrencyCode currencyCode{};
    };

    struct DocTotals {
        double sumInvoiceLineNetAmount{};
        std::optional<double> sumAllowances{std::nullopt};
        std::optional<double> sumCharges{std::nullopt};
        double invoiceTotalAmountWithoutVAT{};
        std::optional<double> invoiceTotalTax{};
        std::optional<double> invoiceTotalVATAmountInAccountingCurrency{};
        double invoiceTotalWithVAT{};
        std::optional<double> paidAmount{};
        std::optional<double> roundingAmount{};
        double amountDueForPayment{};
        XRechnungUtils::ISO4217_CurrencyCode currencyCode{};
    };

    struct VATProp {
        XRechnungUtils::ISO4217_CurrencyCode currencyCode{};
        double taxableAmount{};
        double taxAmount{};
        XRechnungUtils::VATCategory VATCategoryCode{};
        double rate{};
        std::optional<std::u8string> reason{std::nullopt};
        std::optional<std::u8string> reasonCode{std::nullopt};
    };

    struct AdditionalDoc {
        std::u8string reference{};
        std::optional<std::u8string> description{std::nullopt};
        std::optional<std::u8string> location{std::nullopt};
        std::optional<std::byte> document{std::nullopt};
    };

    struct PriceInfo {
        double netPrice{};
        std::optional<double> discount{};
        std::optional<double> grossPrice{};
        std::optional<double> quantity{};
        std::optional<XRechnungUtils::MEASURE_UNIT> quantityMeasureUnit{};
        XRechnungUtils::ISO4217_CurrencyCode currencyCode{};
    };

    struct ItemAttr {
        std::u8string name{};
        std::u8string value{};
    };

    struct ItemInfo {
        std::u8string name{};
        std::optional<std::u8string> description{std::nullopt};
        std::optional<std::u8string> sellerId{std::nullopt};
        std::optional<std::u8string> buyerId{std::nullopt};
        std::optional<std::u8string> standardId{std::nullopt};
        std::vector<std::u8string> classificationIds{};
        std::optional<std::u8string> countryOfOrigin{std::nullopt};
        std::vector<ItemAttr> attributes{};
    };

    struct InvoiceLine {
        std::u8string id{};
        std::optional<std::u8string> note{std::nullopt};
        std::optional<std::u8string> objectId{std::nullopt};
        double quantity{};
        XRechnungUtils::MEASURE_UNIT quantityMeasureUnit{};
        double netAmount{};
        std::optional<std::u8string> orderReference{std::nullopt};
        std::optional<std::u8string> buyerAccountingReference{std::nullopt};
        std::optional<Period> period{std::nullopt};
        std::vector<ChargeProp> allowances{};
        std::vector<ChargeProp> charges{};
        PriceInfo priceDetail{};
        BaseVATProp VATInfo{};
        ItemInfo itemInfo{};
        XRechnungUtils::ISO4217_CurrencyCode currencyCode{};
    };

    struct ElectronicAddress {
        std::u8string electronicAddress;
        XRechnungUtils::EASCode schema;
    };
}// namespace XRechnung
