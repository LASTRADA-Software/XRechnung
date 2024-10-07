#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "XRechnungCurrencyCode.hpp"
#include "XRechnungUtils.hpp"

namespace XMapping {
    namespace XDataTypes {
        struct Amount {
            double content{0};
        };

        struct BinaryObject {
            std::byte content{0};
            std::u8string mimeCode{};
            std::u8string filename{};
        };

        struct Code {
            std::u8string id{};
            std::u8string content{};
        };

        struct Date {
            std::u8string content{};
        };

        struct DocumentReference {
            std::u8string content{};
        };

        struct Identifier {
            std::u8string content{};
            std::optional<std::u8string> schemaIdentifier{std::nullopt};
            std::optional<std::u8string> schemaVersionIdentifier{std::nullopt};
        };

        struct Percentage {
            double content{0};
        };

        struct Quantity {
            double content{0};
        };

        struct Text {
            std::u8string content{};
        };

        struct UnitPriceAmount {
            double content{0};
        };
    }// namespace XDataTypes

    template<typename T>
    inline bool checkValid(const T &t) {
        return !t.content.empty();
    }

    template<typename T>
        requires std::same_as<T, XDataTypes::Percentage> || std::same_as<T, XRechnungUtils::VATCategory> ||
                 std::same_as<T, XDataTypes::Quantity>
    inline bool checkValid(const T &t) {
        return true;
    }

    template<>
    inline bool checkValid(const XRechnungUtils::InvoiceType &t) {
        return t != XRechnungUtils::InvoiceType::Undefined;
    }

    template<XRechnungUtils::StringLiteralU8 lit>
    struct Id {
        static constexpr std::u8string_view id{lit.value};
    };
    template<typename T>
    concept concept_Id = requires(T t) { T::id; };

    template<XRechnungUtils::StringLiteralU8 lit>
    struct Attribute {
        static constexpr std::u8string_view attribute{lit.value};
    };
    template<typename T>
    concept concept_Attribute = requires(T t) { T::attribute; };

    template<XRechnungUtils::StringLiteralU8 lit>
    struct Path {
        static constexpr std::u8string_view path{lit.value};
    };
    template<typename T>
    concept concept_Path = requires(T t) { T::path; };

    template<XRechnungUtils::StringLiteralU8 lit>
    struct OuterPath {
        static constexpr std::u8string_view outerPath{lit.value};
    };
    template<typename T>
    concept concept_OuterPath = requires(T t) { T::outerPath; };

    template<typename... Ts>
    struct entry final {};

    template<concept_Id Id, concept_Path Path, typename XDataType>
    struct entry<Id, Path, XDataType> final {
        static constexpr std::u8string_view id{Id::id};
        static constexpr std::u8string_view path{Path::path};
        XDataType type;

        [[nodiscard]] bool isValid() const { return checkValid(type); }
    };

    template<concept_Id Id, concept_Attribute Attribute, typename XDataType>
    struct entry<Id, Attribute, XDataType> final {
        static constexpr std::u8string_view id{Id::id};
        static constexpr std::u8string_view attribute{Attribute::attribute};
        XDataType type;

        [[nodiscard]] bool isValid() const { return checkValid(type); }
    };

    template<concept_Id Id, concept_OuterPath OuterPath, concept_Path Path, typename XDataType>
    struct entry<Id, OuterPath, Path, XDataType> final {
        static constexpr std::u8string_view id{Id::id};
        static constexpr std::u8string_view outerPath{OuterPath::outerPath};
        static constexpr std::u8string_view path{Path::path};
        XDataType type;

        [[nodiscard]] bool isValid() const { return checkValid(type); }
    };


    using namespace XRechnungUtils;
    struct CurrencyAttribute {
        static constexpr std::u8string_view path{u8"currencyID"};
        ISO4217_CurrencyCode currencyCode{ISO4217_CurrencyCode::Unknown};
    };

    using InvoiceNumber = entry<Id<u8"BT-1">, Path<u8"cbc:ID">, XDataTypes::Identifier>;
    using InvoiceIssueDate = entry<Id<u8"BT-2">, Path<u8"cbc:IssueDate">, XDataTypes::Date>;
    using InvoiceTypeCode = entry<Id<u8"BT-3">, Path<u8"cbc:InvoiceTypeCode">, XRechnungUtils::InvoiceType>;

    struct DocumentCurrencyCode final {
        static constexpr std::u8string_view id{u8"BT-5"};
        static constexpr std::u8string_view path{u8"cbc:DocumentCurrencyCode"};
        XDataTypes::Code type;
        ISO4217_CurrencyCode currencyCode{ISO4217_CurrencyCode::Unknown};

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    using TaxCurrencyCode = entry<Id<u8"BT-6">, Path<u8"cbc:TaxCurrencyCode">, XDataTypes::Code>;

    using TaxPointDate = entry<Id<u8"BT-7">, Path<u8"cbc:TaxPointDate">, XDataTypes::Date>;

    using InvoicePeriodDescriptionCode = entry<Id<u8"BT-8">, Path<u8"cbc:DescriptionCode">, PointDateCode>;

    using DueDate = entry<Id<u8"BT-9">, Path<u8"cbc:DueDate">, XDataTypes::Date>;

    using BuyerReference = entry<Id<u8"BT-10">, Path<u8"cbc:BuyerReference">, XDataTypes::Text>;

    using ProjectReference = entry<Id<u8"BT-11">, OuterPath<u8"cac:ProjectReference">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using ContractDocumentReference = entry<Id<u8"BT-12">, OuterPath<u8"cac:ContractDocumentReference">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using OrderReference = entry<Id<u8"BT-13">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using OrderReferenceSalesOrderID = entry<Id<u8"BT-14">, Path<u8"cbc:SalesOrderID">, XDataTypes::DocumentReference>;

    using ReceiptDocumentReference = entry<Id<u8"BT-15">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using DespatchDocumentReference = entry<Id<u8"BT-16">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using OriginatorDocumentReference = entry<Id<u8"BT-17">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using AdditionalDocumentReferenceIdentifier = entry<Id<u8"BT-18">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using AdditionalDocumentReferenceSchemaId = entry<Id<u8"BT-18-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using AccountingCost = entry<Id<u8"BT-19">, Path<u8"cbc:AccountingCost">, XDataTypes::Text>;

    using PaymentTerms = entry<Id<u8"BT-20">, Path<u8"cbc:Note">, XDataTypes::Text>;

    using InvoiceNoteSubjectCode = entry<Id<u8"BT-21">, Path<u8"cbc:Note">, XDataTypes::Code>;

    using InvoiceNote = entry<Id<u8"BT-22">, Path<u8"cbc:Note">, XDataTypes::Text>;

    using BusinessProcessType = entry<Id<u8"BT-23">, Path<u8"cbc:ProfileID">, XDataTypes::Identifier>;

    using SpecificationIdentifier = entry<Id<u8"BT-24">, Path<u8"cbc:CustomizationID">, XDataTypes::Identifier>;

    using InvoiceDocumentReference = entry<Id<u8"BT-25">, OuterPath<u8"cac:InvoiceDocumentReference">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using InvoiceDocumentReferenceIssueDate = entry<Id<u8"BT-26">, Path<u8"cbc:IssueDate">, XDataTypes::Date>;

    using SellerName = entry<Id<u8"BT-27">, OuterPath<u8"cac:PartyLegalEntity">, Path<u8"cbc:RegistrationName">, XDataTypes::Text>;

    using SellerTradingName = entry<Id<u8"BT-28">, OuterPath<u8"cac:PartyName">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using SellerIdentifier = entry<Id<u8"BT-29">, OuterPath<u8"cac:PartyIdentification">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using SellerIdentifierSchema = entry<Id<u8"BT-29-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using SellerLegalIdentifier = entry<Id<u8"BT-30">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using SellerLegalIdentifierSchema = entry<Id<u8"BT-30-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using SellerVATIdentifier = entry<Id<u8"BT-31">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using SellerTaxRegistrationIdentifier = entry<Id<u8"BT-32">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using SellerAdditionalLegalInformation = entry<Id<u8"BT-33">, Path<u8"cbc:CompanyLegalForm">, XDataTypes::Text>;

    using SellerElectronicAddress = entry<Id<u8"BT-34">, Path<u8"cbc:EndpointID">, XDataTypes::Identifier>;

    using SellerElectronicAddressSchema = entry<Id<u8"BT-34-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using SellerPostalAddressStreetName = entry<Id<u8"BT-35">, Path<u8"cbc:StreetName">, XDataTypes::Text>;

    using SellerPostalAddressAdditionalStreetName = entry<Id<u8"BT-36">, Path<u8"cbc:AdditionalStreetName">, XDataTypes::Text>;

    using SellerPostalAddressAddressLine = entry<Id<u8"BT-36">, Path<u8"cbc:Line">, XDataTypes::Text>;

    using SellerPostalAddressCityName = entry<Id<u8"BT-37">, Path<u8"cbc:CityName">, XDataTypes::Text>;

    using SellerPostalAddressPostalZone = entry<Id<u8"BT-38">, Path<u8"cbc:PostalZone">, XDataTypes::Text>;

    using SellerPostalAddressCountrySubentity = entry<Id<u8"BT-39">, Path<u8"cbc:CountrySubentity">, XDataTypes::Text>;

    /*
    * Ein Code, mit dem das Land bezeichnet wird.
    * Anmerkung: Die Liste der zulässigen Länder ist bei der ISO 3166-1 „Codes for the representation of names of
    * countries and their subdivisions“ erhältlich. Nur die Alpha-2-Darstellung darf verwendet werden.
    */
    using SellerPostalAddressCountryIdentificationCode = entry<Id<u8"BT-40">, OuterPath<u8"cac:Country">, Path<u8"cbc:IdentificationCode">, XDataTypes::Code>;

    using SellerContactName = entry<Id<u8"BT-41">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using SellerContactTelephone = entry<Id<u8"BT-42">, Path<u8"cbc:Telephone">, XDataTypes::Text>;

    using SellerContactEMail = entry<Id<u8"BT-43">, Path<u8"cbc:ElectronicMail">, XDataTypes::Text>;

    using BuyerName = entry<Id<u8"BT-44">, OuterPath<u8"cac:PartyLegalEntity">, Path<u8"cbc:RegistrationName">, XDataTypes::Text>;

    using BuyerTradingName = entry<Id<u8"BT-45">, OuterPath<u8"cac:PartyName">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using BuyerIdentifier = entry<Id<u8"BT-46">, OuterPath<u8"cac:PartyIdentification">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using BuyerIdentifierSchema = entry<Id<u8"BT-46-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using BuyerLegalRegistrationIdentifier = entry<Id<u8"BT-47">, OuterPath<u8"cbc:PartyLegalEntity">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using BuyerLegalRegistrationIdentifierSchema = entry<Id<u8"BT-47-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using BuyerVATIdentifier = entry<Id<u8"BT-48">, OuterPath<u8"cac:PartyTaxScheme">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using BuyerElectronicAddress = entry<Id<u8"BT-49">, Path<u8"cbc:EndpointID">, XDataTypes::Identifier>;

    using BuyerElectronicAddressSchema = entry<Id<u8"BT-49-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using BuyerAddressStreetName = entry<Id<u8"BT-50">, Path<u8"cbc:StreetName">, XDataTypes::Text>;

    using BuyerAddressAdditionalStreetName = entry<Id<u8"BT-51">, Path<u8"cbc:AdditionalStreetName">, XDataTypes::Text>;

    using BuyerAddressAdditionalAddressLine = entry<Id<u8"BT-163">, Path<u8"cbc:Line">, XDataTypes::Text>;

    using BuyerAddressCityName = entry<Id<u8"BT-52">, Path<u8"cbc:CityName">, XDataTypes::Text>;

    using BuyerAddressPostalZone = entry<Id<u8"BT-53">, Path<u8"cbc:PostalZone">, XDataTypes::Text>;

    using BuyerAddressCountrySubentity = entry<Id<u8"BT-54">, Path<u8"cbc:CountrySubentity">, XDataTypes::Text>;

    using BuyerAddressCountryIdentificationCode = entry<Id<u8"BT-55">, OuterPath<u8"cac:Country">, Path<u8"cbc:IdentificationCode">, XDataTypes::Code>;

    using BuyerContact = entry<Id<u8"BT-56">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using BuyerContactTelephone = entry<Id<u8"BT-57">, Path<u8"cbc:Telephone">, XDataTypes::Text>;

    using BuyerContactEMail = entry<Id<u8"BT-58">, Path<u8"cbc:ElectronicMail">, XDataTypes::Text>;

    using PayeeName = entry<Id<u8"BT-59">, OuterPath<u8"cac:PartyName">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using PayeeIdentifier = entry<Id<u8"BT-60">, OuterPath<u8"cac:PartyIdentification">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using PayeeIdentifierSchema = entry<Id<u8"BT-60-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using PayeeLegalRegistrationIdentifier = entry<Id<u8"BT-61">, OuterPath<u8"cac:PartyLegalEntity">, Path<u8"cbc:CompanyID">, XDataTypes::Identifier>;

    using PayeeLegalRegistrationIdentifierSchema = entry<Id<u8"BT-61-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using SellerTaxRepresentative = entry<Id<u8"BT-62">, OuterPath<u8"cac:PartyName">, Path<u8"cbc:Name">, XDataTypes::Text>;


    struct SellerTaxRepresentativeVATIdentifier final {
        SellerTaxRepresentativeVATIdentifier() = default;
        explicit SellerTaxRepresentativeVATIdentifier(std::u8string val) : type{std::move(val)} {}

        static constexpr std::u8string_view id{u8"BT-62"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyTaxScheme"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    using TaxRepresentativePostalAddressStreetName = entry<Id<u8"BT-64">, Path<u8"cbc:StreetName">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressAdditionalStreetName = entry<Id<u8"BT-65">, Path<u8"cbc:AdditionalStreetName">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressAddressLine = entry<Id<u8"BT-164">, Path<u8"cbc:Line">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressCity = entry<Id<u8"BT-66">, Path<u8"cbc:CityName">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressPostCode = entry<Id<u8"BT-67">, Path<u8"cbc:PostalZone">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressCountrySubentity = entry<Id<u8"BT-68">, Path<u8"cbc:CountrySubentity">, XDataTypes::Text>;

    using TaxRepresentativePostalAddressCountryIdentificationCode = entry<Id<u8"BT-69">, Path<u8"cbc:IdentificationCode">, XDataTypes::Code>;

    using DeliveryName = entry<Id<u8"BT-70">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using DeliveryIdentifier = entry<Id<u8"BT-71">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using DeliveryIdentifierSchema = entry<Id<u8"BT-71-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using DeliveryDate = entry<Id<u8"BT-72">, Path<u8"cbc:ActualDeliveryDate">, XDataTypes::Date>;

    using InvoicePeriodStartDate = entry<Id<u8"BT-73">, Path<u8"cbc:StartDate">, XDataTypes::Date>;

    using InvoicePeriodEndDate = entry<Id<u8"BT-74">, Path<u8"cbc:EndDate">, XDataTypes::Date>;

    using DeliveryLocationStreetName = entry<Id<u8"BT-75">, Path<u8"cbc:StreetName">, XDataTypes::Text>;

    using DeliveryLocationAdditionalStreetName = entry<Id<u8"BT-76">, Path<u8"cbc:AdditionalStreetName">, XDataTypes::Text>;

    using DeliveryLocationAdditionalAddressLine = entry<Id<u8"BT-165">, Path<u8"cbc:Line">, XDataTypes::Text>;

    using DeliveryLocationCityName = entry<Id<u8"BT-77">, Path<u8"cbc:CityName">, XDataTypes::Text>;

    using DeliveryLocationPostalZone = entry<Id<u8"BT-78">, Path<u8"cbc:PostalZone">, XDataTypes::Text>;

    using DeliveryLocationCountrySubentity = entry<Id<u8"BT-79">, Path<u8"cbc:CountrySubentity">, XDataTypes::Text>;

    using DeliveryLocationCountryCode = entry<Id<u8"BT-80">, Path<u8"cbc:IdentificationCode">, XDataTypes::Code>;

    using PaymentMeansCode = entry<Id<u8"BT-81">, Path<u8"cbc:PaymentMeansCode">, XDataTypes::Code>;

    using PaymentMeansText = entry<Id<u8"BT-82">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using PaymentMeansPaymentId = entry<Id<u8"BT-83">, Path<u8"cbc:PaymentID">, XDataTypes::Text>;

    using PayeeFinancialAccountIdentifier = entry<Id<u8"BT-84">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using PayeeFinancialAccountName = entry<Id<u8"BT-85">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using PayeeFinancialAccountServiceProvider = entry<Id<u8"BT-86">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using PaymentCardAccountPrimaryNumber = entry<Id<u8"BT-87">, Path<u8"cbc:PrimaryAccountNumberID">, XDataTypes::Text>;

    using PaymentCardAccountHolderName = entry<Id<u8"BT-88">, Path<u8"cbc:HolderName">, XDataTypes::Text>;

    using PaymentMandateIdentifier = entry<Id<u8"BT-89">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using SellerBankAssignedCreditorIdentifier = entry<Id<u8"BT-90">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using PayeeBankAssignedCreditorIdentifier = entry<Id<u8"BT-90">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using PaymentDebitAccountIdentifier = entry<Id<u8"BT-91">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    struct AllowanceChargeAmount final {
        static constexpr std::u8string_view id{u8"BT-92"};
        static constexpr std::u8string_view path{u8"cbc:Amount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };


    struct AllowanceChargeBaseAmount final {
        static constexpr std::u8string_view id{u8"BT-93"};
        static constexpr std::u8string_view path{u8"cbc:BaseAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return type.content > 0.00;
        }
    };


    using AllowanceChargeMultiplier = entry<Id<u8"BT-94">, Path<u8"cbc:MultiplierFactorNumeric">, XDataTypes::Percentage>;

    struct AllowanceChargeTaxCategory final {
        static constexpr std::u8string_view id{u8"BT-95"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type{VATCategory::StandardRate};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using AllowanceChargeTaxCategoryPercentage = entry<Id<u8"BT-96">, Path<u8"cbc:Percent">, XDataTypes::Percentage>;

    using AllowanceChargeReason = entry<Id<u8"BT-97">, Path<u8"cbc:AllowanceChargeReason">, XDataTypes::Text>;

    using AllowanceChargeReasonCode = entry<Id<u8"BT-98">, Path<u8"cbc:AllowanceChargeReason">, XDataTypes::Code>;

    struct DocLevelAllowanceChargeAmount final {
        static constexpr std::u8string_view id{u8"BT-99"};
        static constexpr std::u8string_view path{u8"cbc:Amount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct DocLevelAllowanceChargeBaseAmount final {
        static constexpr std::u8string_view id{u8"BT-100"};
        static constexpr std::u8string_view path{u8"cbc:BaseAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using DocLevelAllowanceChargePercentage = entry<Id<u8"BT-101">, Path<u8"cbc:MultiplierFactorNumeric">, XDataTypes::Percentage>;

    using DocLevelAllowanceChargeTaxCategory = entry<Id<u8"BT-102">, Path<u8"cbc:ID">, VATCategory>;

    using DocLevelAllowanceChargeTaxRate = entry<Id<u8"BT-103">, Path<u8"cbc:Percent">, XDataTypes::Percentage>;

    using DocLevelAllowanceChargeReason = entry<Id<u8"BT-104">, Path<u8"cbc:AllowanceChargeReason">, XDataTypes::Code>;

    using DocLevelAllowanceChargeReasonCode = entry<Id<u8"BT-105">, Path<u8"cbc:AllowanceChargeReasonCode">, XDataTypes::Code>;

    struct LegalMonetaryTotalNetAmount final {
        static constexpr std::u8string_view id{u8"BT-106"};
        static constexpr std::u8string_view path{u8"cbc:LineExtensionAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalAllowanceAmount final {
        static constexpr std::u8string_view id{u8"BT-107"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceTotalAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalCharges final {
        static constexpr std::u8string_view id{u8"BT-108"};
        static constexpr std::u8string_view path{u8"cbc:ChargeTotalAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalTaxExclusiveAmount final {
        static constexpr std::u8string_view id{u8"BT-109"};
        static constexpr std::u8string_view path{u8"cbc:TaxExclusiveAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalVATAmount final {
        static constexpr std::u8string_view id{u8"BT-110"};
        static constexpr std::u8string_view path{u8"cbc:TaxAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalVATAmountCurrency final {
        static constexpr std::u8string_view id{u8"BT-111"};
        static constexpr std::u8string_view path{u8"cbc:TaxAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalTaxInclusiveAmount final {
        static constexpr std::u8string_view id{u8"BT-112"};
        static constexpr std::u8string_view path{u8"cbc:TaxInclusiveAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalPrepaidAmount final {
        static constexpr std::u8string_view id{u8"BT-113"};
        static constexpr std::u8string_view path{u8"cbc:PrepaidAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalPayableRoundingAmount final {
        static constexpr std::u8string_view id{u8"BT-114"};
        static constexpr std::u8string_view path{u8"cbc:PayableRoundingAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct LegalMonetaryTotalPayableAmount final {
        static constexpr std::u8string_view id{u8"BT-115"};
        static constexpr std::u8string_view path{u8"cbc:PayableAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct VATTaxableAmount final {
        static constexpr std::u8string_view id{u8"BT-116"};
        static constexpr std::u8string_view path{u8"cbc:TaxableAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct VATAmount final {
        static constexpr std::u8string_view id{u8"BT-117"};
        static constexpr std::u8string_view path{u8"cbc:TaxAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return currencyAttribute.currencyCode != ISO4217_CurrencyCode::Unknown;
        }
    };

    struct VATCategoryCode final {
        static constexpr std::u8string_view id{u8"BT-118"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type{VATCategory::Unknown};

        [[nodiscard]] bool isValid() const {
            return type != VATCategory::Unknown;
        }
    };

    using VATCategoryRate = entry<Id<u8"BT-119">, Path<u8"cbc:Percent">, XDataTypes::Percentage>;

    using VATExemptionReason = entry<Id<u8"BT-120">, Path<u8"cbc:TaxExemptionReason">, XDataTypes::Text>;

    using VATExemptionReasonCode = entry<Id<u8"BT-121">, Path<u8"cbc:TaxExemptionReasonCode">, XDataTypes::Code>;

    using SupportingDocumentReferenceIdentifier = entry<Id<u8"BT-122">, Path<u8"cbc:ID">, XDataTypes::DocumentReference>;

    using AdditionalDocumentReferenceDescription = entry<Id<u8"BT-123">, Path<u8"cbc:DocumentDescription">, XDataTypes::Text>;

    using AdditionalDocumentExternalReference = entry<Id<u8"BT-124">, Path<u8"cbc:URI">, XDataTypes::Text>;

    using AdditionalDocumentAttached = entry<Id<u8"BT-125">, Path<u8"cbc:EmbeddedDocumentBinaryObject">, XDataTypes::BinaryObject>;

    using AdditionalDocumentAttachedMimeCode = entry<Id<u8"BT-125-1">, Attribute<u8"mimeCode">, XDataTypes::Text>;

    using AdditionalDocumentAttachedFilename = entry<Id<u8"BT-125-1">, Attribute<u8"filename">, XDataTypes::Text>;

    using InvoiceLineIdentifier = entry<Id<u8"BT-126">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using InvoiceLineNote = entry<Id<u8"BT-127">, Path<u8"cbc:Note">, XDataTypes::Text>;

    using InvoiceLineObjectIdentifier = entry<Id<u8"BT-128">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using InvoiceLineObjectIdentifierSchema = entry<Id<u8"BT-128-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using InvoiceLineQuantity = entry<Id<u8"BT-129">, Path<u8"cbc:InvoicedQuantity">, XDataTypes::Quantity>;

    using InvoiceLineQuantityUnit = entry<Id<u8"BT-130">, Attribute<u8"unitCode">, XDataTypes::Code>;

    struct InvoiceLineNetAmount final {
        static constexpr std::u8string_view id{u8"BT-131"};
        static constexpr std::u8string_view path{u8"cbc:LineExtensionAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using InvoiceLineOrderReference = entry<Id<u8"BT-132">, Path<u8"cbc:LineID">, XDataTypes::DocumentReference>;

    using InvoiceLineAccountingCost = entry<Id<u8"BT-133">, Path<u8"cbc:AccountingCost">, XDataTypes::Text>;

    using InvoiceLinePeriodStartDate = entry<Id<u8"BT-134">, Path<u8"cbc:StartDate">, XDataTypes::Date>;

    using InvoiceLinePeriodEndDate = entry<Id<u8"BT-135">, Path<u8"cbc:EndDate">, XDataTypes::Date>;

    struct InvoiceLineAllowanceAmount final {
        static constexpr std::u8string_view id{u8"BT-136"};
        static constexpr std::u8string_view path{u8"cbc:Amount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineAllowanceBaseAmount final {
        static constexpr std::u8string_view id{u8"BT-137"};
        static constexpr std::u8string_view path{u8"cbc:BaseAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using InvoiceLineAllowancePercentage = entry<Id<u8"BT-138">, Path<u8"cbc:MultiplierFactorNumeric">, XDataTypes::Percentage>;

    using InvoiceLineAllowanceReason = entry<Id<u8"BT-139">, Path<u8"cbc:AllowanceChargeReason">, XDataTypes::Text>;

    using InvoiceLineAllowanceReasonCode = entry<Id<u8"BT-140">, Path<u8"cbc:AllowanceChargeReasonCode">, XDataTypes::Code>;

    struct InvoiceLineChargeAmount final {
        static constexpr std::u8string_view id{u8"BT-141"};
        static constexpr std::u8string_view path{u8"cbc:Amount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineChargeBaseAmount final {
        static constexpr std::u8string_view id{u8"BT-142"};
        static constexpr std::u8string_view path{u8"cbc:BaseAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using InvoiceLineChargePercentage = entry<Id<u8"BT-143">, Path<u8"cbc:MultiplierFactorNumeric">, XDataTypes::Percentage>;

    using InvoiceLineChargeReason = entry<Id<u8"BT-144">, Path<u8"cbc:AllowanceChargeReason">, XDataTypes::Text>;

    using InvoiceLineChargeReasonCode = entry<Id<u8"BT-145">, Path<u8"cbc:AllowanceChargeReasonCode">, XDataTypes::Code>;

    struct ItemNetPrice final {
        static constexpr std::u8string_view id{u8"BT-146"};
        static constexpr std::u8string_view path{u8"cbc:PriceAmount"};
        XDataTypes::UnitPriceAmount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct ItemPriceDiscount final {
        static constexpr std::u8string_view id{u8"BT-147"};
        static constexpr std::u8string_view path{u8"cbc:Amount"};
        XDataTypes::UnitPriceAmount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct ItemGrossPrice final {
        static constexpr std::u8string_view id{u8"BT-148"};
        static constexpr std::u8string_view path{u8"cbc:BaseAmount"};
        XDataTypes::UnitPriceAmount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using ItemBaseQuantity = entry<Id<u8"BT-149">, Path<u8"cbc:BaseQuantity">, XDataTypes::Quantity>;

    using ItemBaseQuantityCode = entry<Id<u8"BT-150">, Attribute<u8"unitCode">, XDataTypes::Code>;

    struct ItemVATCategoryCode final {
        static constexpr std::u8string_view id{u8"BT-151"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type{VATCategory::StandardRate};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    using ItemVATRate = entry<Id<u8"BT-152">, Path<u8"cbc:Percent">, XDataTypes::Percentage>;

    using ItemName = entry<Id<u8"BT-153">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using ItemDescription = entry<Id<u8"BT-154">, Path<u8"cbc:Description">, XDataTypes::Text>;

    using ItemSellerIdentifier = entry<Id<u8"BT-155">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using ItemBuyerIdentifier = entry<Id<u8"BT-156">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using ItemStandardIdentifier = entry<Id<u8"BT-157">, Path<u8"cbc:ID">, XDataTypes::Identifier>;

    using ItemStandardIdentifierSchema = entry<Id<u8"BT-157-1">, Path<u8"schemeID">, XDataTypes::Text>;

    using ItemClassificationIdentifier = entry<Id<u8"BT-158">, Path<u8"cbc:ItemClassificationCode">, XDataTypes::Identifier>;

    using ItemClassificationIdentifierSchema = entry<Id<u8"BT-158-1">, Attribute<u8"schemeID">, XDataTypes::Text>;

    using ItemClassificationIdentifierSchemaVersion = entry<Id<u8"BT-158-2">, Attribute<u8"listVersionID">, XDataTypes::Text>;

    using ItemOriginCountryCode = entry<Id<u8"BT-159">, Path<u8"cbc:IdentificationCode">, XDataTypes::Code>;

    using ItemAttributeName = entry<Id<u8"BT-160">, Path<u8"cbc:Name">, XDataTypes::Text>;

    using ItemAttributeValue = entry<Id<u8"BT-161">, Path<u8"cbc:Value">, XDataTypes::Text>;


    struct INVOICE_NOTE final {
        static constexpr std::u8string_view id{u8"BG-1"};
        static constexpr std::u8string_view path{};

        std::optional<InvoiceNoteSubjectCode> subjectCode{std::nullopt};
        InvoiceNote note{};

        [[nodiscard]] bool isValid() const {
            return note.isValid();
        }
    };

    struct PROCESS_CONTROL final {
        static constexpr std::u8string_view id{u8"BG-2"};
        static constexpr std::u8string_view path{};

        BusinessProcessType processType{u8"urn:fdc:peppol.eu:2017:poacc:billing:01:1.0"};
        SpecificationIdentifier specificationIdentifier{u8"urn:cen.eu:en16931:2017#compliant#urn:xeinkauf.de:kosit:xrechnung_3.0"};

        [[nodiscard]] bool isValid() const {
            return processType.isValid() && specificationIdentifier.isValid();
        }
    };

    struct VAT_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-3"};
        static constexpr std::u8string_view path{};

        InvoiceDocumentReference documentReference{};
        std::optional<InvoiceDocumentReferenceIssueDate> issueDate{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return documentReference.isValid();
        }
    };

    struct VATTaxScheme final {
        static constexpr std::u8string_view id{u8"VAT"};
        static constexpr std::u8string_view outerPath{u8"cac:TaxScheme"};
        static constexpr std::u8string_view path{u8"cbc:ID"};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct SELLER_POSTAL_ADDRESS final {
        static constexpr std::u8string_view id{u8"BG-5"};
        static constexpr std::u8string_view path{u8"cac:PostalAddress"};

        std::optional<SellerPostalAddressStreetName> address{std::nullopt};
        std::optional<SellerPostalAddressAdditionalStreetName> additional{std::nullopt};
        std::optional<SellerPostalAddressAddressLine> additionalAddon{std::nullopt};
        SellerPostalAddressCityName city{};
        SellerPostalAddressPostalZone postalCode{};
        std::optional<SellerPostalAddressCountrySubentity> countrySubentity{std::nullopt};
        SellerPostalAddressCountryIdentificationCode countryCode{};

        [[nodiscard]] bool isValid() const {
            return city.isValid() && postalCode.isValid() && countryCode.isValid();
        }
    };

    struct SELLER_CONTACT final {
        static constexpr std::u8string_view id{u8"BG-6"};
        static constexpr std::u8string_view path{u8"cac:Contact"};

        SellerContactName name{};
        SellerContactTelephone telephone{};
        SellerContactEMail eMail{};

        [[nodiscard]] bool isValid() const {
            return name.isValid() && telephone.isValid() && eMail.isValid();
        }
    };

    struct SELLER final {
        static constexpr std::u8string_view id{u8"BG-4"};
        static constexpr std::u8string_view path{u8"cac:AccountingSupplierParty"};
        static constexpr std::u8string_view subPath{u8"cac:Party"};

        SellerName name{};
        std::optional<SellerTradingName> tradingName{std::nullopt};
        std::vector<SellerIdentifier> identifier{};
        std::optional<SellerLegalIdentifier> legalIdentifier{std::nullopt};
        std::optional<SellerVATIdentifier> vatIdentifier{std::nullopt};
        std::optional<SellerTaxRegistrationIdentifier> taxRegistrationIdentifier{std::nullopt};
        std::optional<SellerAdditionalLegalInformation> additionalLegalInformation{std::nullopt};
        SellerElectronicAddress electronicAddress{};
        SellerElectronicAddressSchema electronicAddressSchema{};
        SELLER_POSTAL_ADDRESS address{};
        SELLER_CONTACT contact{};

        [[nodiscard]] bool isValid() const {
            return name.isValid() && (vatIdentifier.has_value() || legalIdentifier.has_value());
        }
    };


    struct BUYER_POSTAL_ADDRESS final {
        static constexpr std::u8string_view id{u8"BG-8"};
        static constexpr std::u8string_view path{u8"cac:PostalAddress"};

        std::optional<BuyerAddressStreetName> address{std::nullopt};
        std::optional<BuyerAddressAdditionalStreetName> additions{std::nullopt};
        std::optional<BuyerAddressAdditionalAddressLine> additionsAddon{std::nullopt};
        BuyerAddressCityName city{};
        BuyerAddressPostalZone postalCode{};
        std::optional<BuyerAddressCountrySubentity> countrySubdivision{std::nullopt};
        BuyerAddressCountryIdentificationCode countryCode{};

        [[nodiscard]] bool isValid() const {
            return city.isValid() &&
                   postalCode.isValid() &&
                   countryCode.isValid();
        }
    };

    struct BUYER_CONTACT final {
        static constexpr std::u8string_view id{u8"BG-9"};
        static constexpr std::u8string_view path{u8"cac:Contact"};

        std::optional<BuyerContact> contactPoint{std::nullopt};
        std::optional<BuyerContactTelephone> telephone{std::nullopt};
        std::optional<BuyerContactEMail> email{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct BUYER final {
        static constexpr std::u8string_view id{u8"BG-7"};
        static constexpr std::u8string_view path{u8"cac:AccountingCustomerParty"};
        static constexpr std::u8string_view subPath{u8"cac:Party"};

        std::optional<BuyerName> name{};
        std::optional<BuyerTradingName> tradingName{std::nullopt};
        std::optional<BuyerIdentifier> buyerId{std::nullopt};
        std::optional<BuyerLegalRegistrationIdentifier> legalRegistrationId{std::nullopt};
        std::optional<BuyerVATIdentifier> vatIdentifier{std::nullopt};
        BuyerElectronicAddress electronicAddress{};
        BuyerElectronicAddressSchema electronicAddressSchema;
        BUYER_POSTAL_ADDRESS address{};
        std::optional<BUYER_CONTACT> contact{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return (name.has_value() || tradingName.has_value() || buyerId.has_value()) && electronicAddress.isValid() && address.isValid();
        }
    };

    struct PAYEE final {
        static constexpr std::u8string_view id{u8"BG-10"};
        static constexpr std::u8string_view path{u8"cac:PayeeParty"};

        PayeeName name{};
        std::optional<PayeeIdentifier> identifier{std::nullopt};
        std::optional<PayeeLegalRegistrationIdentifier> legalRegistrationId{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return name.isValid();
        }
    };

    struct SELLER_TAX_REPRESENTATIVE_POSTAL_ADDRESS final {
        static constexpr std::u8string_view id{u8"BG-12"};
        static constexpr std::u8string_view path{u8"cac:PostalAddress"};

        std::optional<TaxRepresentativePostalAddressStreetName> address{std::nullopt};
        std::optional<TaxRepresentativePostalAddressAdditionalStreetName> additional{std::nullopt};
        std::optional<TaxRepresentativePostalAddressAddressLine> additionalAddon{std::nullopt};
        std::optional<TaxRepresentativePostalAddressCity> city{std::nullopt};
        std::optional<TaxRepresentativePostalAddressPostCode> postalCode{std::nullopt};
        std::optional<TaxRepresentativePostalAddressCountrySubentity> addressSubentity{std::nullopt};
        TaxRepresentativePostalAddressCountryIdentificationCode countryCode{};

        [[nodiscard]] bool isValid() const {
            return countryCode.isValid();
        }
    };

    struct SELLER_TAX_REPRESENTATIVE_PARTY final {
        static constexpr std::u8string_view id{u8"BG-11"};
        static constexpr std::u8string_view path{u8"cac:TaxRepresentativeParty"};

        SellerTaxRepresentative representative{};
        SellerTaxRepresentativeVATIdentifier vatIdentifier{};
        SELLER_TAX_REPRESENTATIVE_POSTAL_ADDRESS address{};

        [[nodiscard]] bool isValid() const {
            return representative.isValid() &&
                   vatIdentifier.isValid() &&
                   address.isValid();
        }
    };

    struct INVOICE_PERIOD final {
        static constexpr std::u8string_view id{u8"BG-14"};
        static constexpr std::u8string_view path{u8"cac:InvoicePeriod"};

        std::optional<InvoicePeriodStartDate> startDate{std::nullopt};
        std::optional<InvoicePeriodEndDate> endDate{std::nullopt};
        std::optional<InvoicePeriodDescriptionCode> descriptionCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            const bool startDateValid = startDate ? startDate.value().isValid() : true;
            const bool endDateValid = endDate ? endDate.value().isValid() : true;
            return startDateValid && endDateValid;
        }
    };

    struct DELIVER_TO_ADDRESS final {
        static constexpr std::u8string_view id{u8"BG-15"};
        static constexpr std::u8string_view path{u8"cac:Address"};

        std::optional<DeliveryLocationStreetName> address{std::nullopt};
        std::optional<DeliveryLocationAdditionalStreetName> additional{std::nullopt};
        std::optional<DeliveryLocationAdditionalAddressLine> additionalAddon{std::nullopt};
        DeliveryLocationCityName deliveryCityName{};
        DeliveryLocationPostalZone deliveryPostalCode{};
        std::optional<DeliveryLocationCountrySubentity> locationCountrySubentity{std::nullopt};
        DeliveryLocationCountryCode deliveryCountryCode{};

        [[nodiscard]] bool isValid() const {
            return deliveryCityName.isValid() &&
                   deliveryPostalCode.isValid() &&
                   deliveryCountryCode.isValid();
        }
    };

    struct DELIVERY_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-13"};
        static constexpr std::u8string_view path{u8"cac:Delivery"};

        std::optional<DeliveryName> name{std::nullopt};
        std::optional<DeliveryIdentifier> identifier{};
        std::optional<DeliveryDate> deliveryDate{std::nullopt};
        std::optional<INVOICE_PERIOD> invoicePeriod{std::nullopt};
        std::optional<DELIVER_TO_ADDRESS> deliverToAddress{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct CREDIT_TRANSFER final {
        static constexpr std::u8string_view id{u8"BG-17"};
        static constexpr std::u8string_view path{u8"cac:PayeeFinancialAccount"};

        PayeeFinancialAccountIdentifier accountIdentifier{};
        std::optional<PayeeFinancialAccountName> accountName{std::nullopt};
        std::optional<PayeeFinancialAccountServiceProvider> accountServiceProvide{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return accountIdentifier.isValid();
        }
    };

    struct PAYMENT_CARD_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-18"};
        static constexpr std::u8string_view path{u8"cac:CardAccount"};

        PaymentCardAccountPrimaryNumber primaryNumber{};
        std::optional<PaymentCardAccountHolderName> holderName{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return primaryNumber.isValid();
        }
    };

    struct DIRECT_DEBIT final {
        static constexpr std::u8string_view id{u8"BG-19"};
        static constexpr std::u8string_view path{u8"cac:PaymentMandate"};

        PaymentMandateIdentifier mandateIdentifier{};
        SellerBankAssignedCreditorIdentifier assignedCreditorIdentifier{};
        PayeeBankAssignedCreditorIdentifier debitAccountIdentifier{};

        [[nodiscard]] bool isValid() const {
            return mandateIdentifier.isValid() &&
                   assignedCreditorIdentifier.isValid() &&
                   debitAccountIdentifier.isValid();
        }
    };

    struct PAYMENT_INSTRUCTIONS final {
        static constexpr std::u8string_view id{u8"BG-16"};
        static constexpr std::u8string_view path{u8"cac:PaymentMeans"};

        PaymentMeansCode code{};
        std::optional<PaymentMeansText> text{std::nullopt};
        std::optional<PaymentMeansPaymentId> paymentId{std::nullopt};
        std::vector<CREDIT_TRANSFER> creditTransfer{};
        std::optional<PAYMENT_CARD_INFORMATION> cardInformation{std::nullopt};
        std::optional<DIRECT_DEBIT> directDebit{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return code.isValid();
        }
    };

    struct DOCUMENT_ALLOWANCES final {
        static constexpr std::u8string_view id{u8"BG-20"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{false};
        AllowanceChargeAmount amount{};
        std::optional<AllowanceChargeBaseAmount> baseAmount{std::nullopt};
        AllowanceChargeMultiplier percentage{};
        AllowanceChargeTaxCategory taxCategoryCode{};
        AllowanceChargeTaxCategoryPercentage vatRate{};
        std::optional<AllowanceChargeReason> allowanceReason{std::nullopt};
        std::optional<AllowanceChargeReasonCode> allowanceReasonCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return amount.isValid() && taxCategoryCode.isValid();
        }
    };

    struct DOCUMENT_CHARGES final {
        static constexpr std::u8string_view id{u8"BG-21"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{false};
        DocLevelAllowanceChargeAmount amount{};
        std::optional<DocLevelAllowanceChargeBaseAmount> baseAmount{std::nullopt};
        std::optional<DocLevelAllowanceChargePercentage> percentage{std::nullopt};
        DocLevelAllowanceChargeTaxCategory taxCategory{};
        DocLevelAllowanceChargeTaxRate taxRate{};
        std::optional<DocLevelAllowanceChargeReason> reason{std::nullopt};
        std::optional<DocLevelAllowanceChargeReasonCode> reasonCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return amount.isValid() && taxCategory.isValid();
        }
    };

    struct DOCUMENT_TOTALS final {
        static constexpr std::u8string_view id{u8"BG-22"};
        static constexpr std::u8string_view path{u8"cac:LegalMonetaryTotal"};

        LegalMonetaryTotalNetAmount netAmount{};
        std::optional<LegalMonetaryTotalAllowanceAmount> totalAllowanceAmount{std::nullopt};
        std::optional<LegalMonetaryTotalCharges> totalCharges{std::nullopt};
        LegalMonetaryTotalTaxExclusiveAmount amountWithoutTax{};
        std::optional<LegalMonetaryTotalVATAmount> taxAmount{std::nullopt};
        std::optional<LegalMonetaryTotalVATAmountCurrency> taxAmountCurrency{std::nullopt};
        LegalMonetaryTotalTaxInclusiveAmount amountWithTax{};
        std::optional<LegalMonetaryTotalPrepaidAmount> prepaidAmount{std::nullopt};
        std::optional<LegalMonetaryTotalPayableRoundingAmount> roundingAmount{std::nullopt};
        LegalMonetaryTotalPayableAmount paymentAmountDue{};
        /*
         * Der ausstehende Betrag, der zu zahlen ist.
         * Anmerkung: Dieser Betrag ist der "Invoice total amount with VAT" (BT-112) abzüglich des "Paid amount" (BT-113). Im Falle einer vollständig beglichenen Rechnung ist dieser Betrag gleich null. Der Betrag ist negativ, falls
         * der "Paid amount" (BT-113) größer als der "Invoice total amount with VAT" (BT-112) ist
         */
        [[nodiscard]] bool isValid() const {
            return netAmount.isValid() &&
                   amountWithoutTax.isValid() &&
                   amountWithTax.isValid() &&
                   paymentAmountDue.isValid();
        }
    };

    struct VAT_BREAKDOWN final {
        static constexpr std::u8string_view id{u8"BG-23"};
        static constexpr std::u8string_view path{u8"cac:TaxSubtotal"};

        VATTaxableAmount taxableAmount{};
        VATAmount taxAmount{};
        VATCategoryCode categoryCode{};
        VATCategoryRate categoryRate{};
        std::optional<VATExemptionReason> reason{std::nullopt};
        std::optional<VATExemptionReasonCode> reasonCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return taxableAmount.isValid() &&
                   taxAmount.isValid() &&
                   categoryCode.isValid() &&
                   categoryRate.isValid();
        }
    };

    struct ADDITIONAL_SUPPORTING_DOCUMENTS final {
        static constexpr std::u8string_view id{u8"BG-24"};
        static constexpr std::u8string_view path{u8"cac:AdditionalDocumentReference"};

        SupportingDocumentReferenceIdentifier referenceIdentifier{};
        std::optional<AdditionalDocumentReferenceDescription> referenceDescription{std::nullopt};
        std::optional<AdditionalDocumentExternalReference> externalReference{std::nullopt};
        std::optional<AdditionalDocumentAttached> documentAttached{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return referenceIdentifier.isValid();
        }
    };

    struct INVOICE_LINE_PERIOD final {
        static constexpr std::u8string_view id{u8"BG-26"};
        static constexpr std::u8string_view path{u8"cac:InvoicePeriod"};

        std::optional<InvoiceLinePeriodStartDate> startDate{std::nullopt};
        std::optional<InvoiceLinePeriodEndDate> endDate{std::nullopt};

        [[nodiscard]] bool isValid() const {
            const bool startDateValid = startDate.has_value() ? startDate.value().isValid() : false;
            const bool endDateValid = endDate.has_value() ? endDate.value().isValid() : false;
            return startDateValid && endDateValid;
        }
    };

    struct INVOICE_LINE_ALLOWANCES final {
        static constexpr std::u8string_view id{u8"BG-27"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{false};
        InvoiceLineAllowanceAmount amount{};
        InvoiceLineAllowanceReasonCode reasonCode{};
        std::optional<InvoiceLineAllowanceBaseAmount> baseAmount{std::nullopt};
        std::optional<InvoiceLineAllowancePercentage> percentage{std::nullopt};
        std::optional<InvoiceLineAllowanceReason> reason{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return amount.isValid();
        }
    };

    struct INVOICE_LINE_CHARGES final {
        static constexpr std::u8string_view id{u8"BG-28"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{true};
        InvoiceLineChargeAmount amount{};
        std::optional<InvoiceLineChargeBaseAmount> baseAmount{std::nullopt};
        std::optional<InvoiceLineChargePercentage> percentage{std::nullopt};
        std::optional<InvoiceLineChargeReason> reason{std::nullopt};
        InvoiceLineChargeReasonCode reasonCode{};

        [[nodiscard]] bool isValid() const {
            return amount.isValid();
        }
    };

    struct PRICE_DETAILS final {
        static constexpr std::u8string_view id{u8"BG-29"};
        static constexpr std::u8string_view path{u8"cac:Price"};

        ItemNetPrice netPrice{};
        std::optional<ItemPriceDiscount> discount{std::nullopt};
        std::optional<ItemGrossPrice> grossPrice{std::nullopt};
        std::optional<ItemBaseQuantity> quantity{std::nullopt};
        std::optional<ItemBaseQuantityCode> quantityCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return netPrice.isValid();
        }
    };

    struct LINE_VAT_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-30"};
        static constexpr std::u8string_view path{u8"cac:ClassifiedTaxCategory"};

        ItemVATCategoryCode categoryCode{};
        std::optional<ItemVATRate> percentage{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return categoryCode.isValid();
        }
    };

    struct ITEM_ATTRIBUTES final {
        static constexpr std::u8string_view id{u8"BG-32"};
        static constexpr std::u8string_view path{u8"cac:AdditionalItemProperty"};

        ItemAttributeName name{};
        ItemAttributeValue value{};

        [[nodiscard]] bool isValid() const {
            return name.isValid() && value.isValid();
        }
    };

    struct ITEM_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-31"};
        static constexpr std::u8string_view path{u8"cac:Item"};

        ItemName name{};
        std::optional<ItemDescription> description{std::nullopt};
        std::optional<ItemSellerIdentifier> sellerIdentifier{std::nullopt};
        std::optional<ItemBuyerIdentifier> buyerIdentifier{std::nullopt};
        std::optional<ItemStandardIdentifier> standardIdentifier{std::nullopt};
        std::vector<ItemClassificationIdentifier> classificationIdentifier{};
        std::optional<ItemOriginCountryCode> itemOriginCountry{std::nullopt};
        std::vector<ITEM_ATTRIBUTES> attributes{};

        [[nodiscard]] bool isValid() const {
            return name.isValid();
        }
    };

    // Die Art der Fremdforderung
    struct ThirdPartyPaymentType final {
        static constexpr std::u8string_view id{u8"BG-DEX-001"};
        static constexpr std::u8string_view path{u8"cbc:"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    // Der Betrag der Fremdforderung.
    // Anmerkung: Beträge aus Fremdforderung sind Bruttobeträge. Es erfolgt hierbei keine Umsatzsteueraufschlüsselung
    struct ThirdPartyPaymentAmount final {
        static constexpr std::u8string_view id{u8"BG-DEX-002"};
        static constexpr std::u8string_view path{u8"cbc:"};
        XDataTypes::Amount type;

        [[nodiscard]] bool isValid() const {
            return type.content > 0.0;
        }
    };

    // Eine innerhalb der Rechnung eindeutige Beschreibung der Fremdforderung.
    struct ThirdPartyPaymentDescription final {
        static constexpr std::u8string_view id{u8"BG-DEX-003"};
        static constexpr std::u8string_view path{u8"cbc:"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct THIRD_PARTY_PAYMENT final {
        static constexpr std::u8string_view id{u8"BG-DEX-09"};
        static constexpr std::u8string_view path{u8"cbc:"};

        ThirdPartyPaymentType paymentType{};
        ThirdPartyPaymentAmount amount{};
        ThirdPartyPaymentDescription description{};

        [[nodiscard]] bool isValid() const {
            return paymentType.isValid() && amount.isValid() && description.isValid();
        }
    };

    struct SUB_LINE_VAT_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-DEX-06"};
        static constexpr std::u8string_view path{u8"cac:ClassifiedTaxCategory"};

        ItemVATCategoryCode categoryCode{};
        std::optional<ItemVATRate> percentage{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return categoryCode.isValid();
        }
    };

    struct SUB_PRICE_DETAILS final {
        static constexpr std::u8string_view id{u8"BG-DEX-07"};
        static constexpr std::u8string_view path{u8"cac:Price"};

        ItemNetPrice netPrice{};
        std::optional<ItemPriceDiscount> discount{std::nullopt};
        std::optional<ItemGrossPrice> grossPrice{std::nullopt};
        std::optional<ItemBaseQuantity> quantity{std::nullopt};
        std::optional<ItemBaseQuantityCode> quantityCode{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return netPrice.isValid();
        }
    };

    struct SUB_INVOICE_LINE_PERIOD final {
        static constexpr std::u8string_view id{u8"BG-DEX-05"};
        static constexpr std::u8string_view path{u8"cac:InvoicePeriod"};

        std::optional<InvoiceLinePeriodStartDate> startDate{std::nullopt};
        std::optional<InvoiceLinePeriodEndDate> endDate{std::nullopt};

        [[nodiscard]] bool isValid() const {
            const bool startDateValid = startDate.has_value() ? startDate.value().isValid() : false;
            const bool endDateValid = endDate.has_value() ? endDate.value().isValid() : false;
            return startDateValid && endDateValid;
        }
    };

    struct SUB_ITEM_ATTRIBUTES final {
        static constexpr std::u8string_view id{u8"BG-DEX-08"};
        static constexpr std::u8string_view path{u8"cac:AdditionalItemProperty"};

        ItemAttributeName name{};
        ItemAttributeValue value{};

        [[nodiscard]] bool isValid() const {
            return name.isValid() && value.isValid();
        }
    };

    struct SUB_ITEM_INFORMATION final {
        static constexpr std::u8string_view id{u8"BG-DEX-02"};
        static constexpr std::u8string_view path{u8"cac:Item"};

        ItemName name{};
        std::optional<ItemDescription> description{std::nullopt};
        std::optional<ItemSellerIdentifier> sellerIdentifier{std::nullopt};
        std::optional<ItemBuyerIdentifier> buyerIdentifier{std::nullopt};
        std::optional<ItemStandardIdentifier> standardIdentifier{std::nullopt};
        std::vector<ItemClassificationIdentifier> classificationIdentifier{};
        std::optional<ItemOriginCountryCode> itemOriginCountry{std::nullopt};
        std::vector<SUB_ITEM_ATTRIBUTES> attributes{};

        [[nodiscard]] bool isValid() const {
            return name.isValid();
        }
    };

    struct SUB_INVOICE_LINE_ALLOWANCES final {
        static constexpr std::u8string_view id{u8"BG-DEX-03"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{false};
        InvoiceLineAllowanceAmount amount{};
        InvoiceLineAllowanceReasonCode reasonCode{};
        std::optional<InvoiceLineAllowanceBaseAmount> baseAmount{std::nullopt};
        std::optional<InvoiceLineAllowancePercentage> percentage{std::nullopt};
        std::optional<InvoiceLineAllowanceReason> reason{std::nullopt};

        [[nodiscard]] bool isValid() const {
            return amount.isValid();
        }
    };

    struct SUB_INVOICE_LINE_CHARGES final {
        static constexpr std::u8string_view id{u8"BG-DEX-04"};
        static constexpr std::u8string_view path{u8"cac:AllowanceCharge"};

        bool chargeIndicator{true};
        InvoiceLineChargeAmount amount{};
        std::optional<InvoiceLineChargeBaseAmount> baseAmount{std::nullopt};
        std::optional<InvoiceLineChargePercentage> percentage{std::nullopt};
        std::optional<InvoiceLineChargeReason> reason{std::nullopt};
        InvoiceLineChargeReasonCode reasonCode{};

        [[nodiscard]] bool isValid() const {
            return amount.isValid();
        }
    };

    struct SUB_INVOICE_LINE final {
        static constexpr std::u8string_view id{u8"BG-DEX-01"};
        static constexpr std::u8string_view path{u8"cac:SubInvoiceLine"};

        InvoiceLineIdentifier identifier{};
        std::optional<InvoiceLineNote> note{std::nullopt};
        std::optional<InvoiceLineObjectIdentifier> objectIdentifier{std::nullopt};

        InvoiceLineQuantity quantity{};
        InvoiceLineQuantityUnit quantityUnit{};
        InvoiceLineNetAmount netAmount{};
        std::optional<InvoiceLineOrderReference> documentReference{std::nullopt};
        std::optional<InvoiceLineAccountingCost> buyerAccountingReference{std::nullopt};

        SUB_ITEM_INFORMATION itemInformation{};
        std::vector<SUB_INVOICE_LINE_ALLOWANCES> allowances{};
        std::vector<SUB_INVOICE_LINE_CHARGES> charges{};
        std::optional<SUB_INVOICE_LINE_PERIOD> period{};
        SUB_LINE_VAT_INFORMATION vatInformation{};
        SUB_PRICE_DETAILS priceDetails{};
        std::vector<SUB_INVOICE_LINE> subLines{};
    };

    struct INVOICE_LINE final {
        static constexpr std::u8string_view id{u8"BG-25"};
        static constexpr std::u8string_view path{u8"cac:InvoiceLine"};

        InvoiceLineIdentifier identifier{};
        std::optional<InvoiceLineNote> note{std::nullopt};

        // Eine vom Verkäufer angegebene Kennung für ein Objekt, auf das sich die Rechnungsposition bezieht (z. B. Zählernummer, Telefonnummer, Kfz-Kennzeichen, versicherte Person, Abonnement-Nummer, Rufnummer).
        std::optional<InvoiceLineObjectIdentifier> objectIdentifier{std::nullopt};

        InvoiceLineQuantity quantity{};
        InvoiceLineQuantityUnit quantityUnit{};
        InvoiceLineNetAmount netAmount{};
        std::optional<InvoiceLineOrderReference> orderReference{std::nullopt};
        std::optional<InvoiceLineAccountingCost> buyerAccountingReference{std::nullopt};
        INVOICE_LINE_PERIOD period{};
        std::vector<INVOICE_LINE_ALLOWANCES> allowances{};
        std::vector<INVOICE_LINE_CHARGES> charges{};
        PRICE_DETAILS priceDetails{};
        LINE_VAT_INFORMATION vatInformation{};
        ITEM_INFORMATION itemInformation{};

        std::vector<SUB_INVOICE_LINE> subLines{};
        std::optional<THIRD_PARTY_PAYMENT> thirdPartyPayment{};

        [[nodiscard]] bool isValid() const {
            return identifier.isValid() &&
                   quantity.isValid() &&
                   quantityUnit.isValid() &&
                   netAmount.isValid() &&
                   period.isValid() &&
                   priceDetails.isValid() &&
                   vatInformation.isValid() &&
                   itemInformation.isValid();
        }
    };
}// namespace XMapping
