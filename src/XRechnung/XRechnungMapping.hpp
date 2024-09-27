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

    using namespace XRechnungUtils;

    struct CurrencyAttribute {
        static constexpr std::u8string_view path{u8"currencyID"};
        ISO4217_CurrencyCode currencyCode{ISO4217_CurrencyCode::Unknown};
    };

    struct InvoiceNumber final {
        static constexpr std::u8string_view id{u8"BT-1"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceIssueDate final {
        static constexpr std::u8string_view id{u8"BT-2"};
        static constexpr std::u8string_view path{u8"cbc:IssueDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            // maybe add date validation?
            return !type.content.empty();
        }
    };

    struct InvoiceTypeCode final {
        static constexpr std::u8string_view id{u8"BT-3"};
        static constexpr std::u8string_view path{u8"cbc:InvoiceTypeCode"};
        InvoiceType type{InvoiceType::Undefined};

        [[nodiscard]] bool isValid() const {
            return type != InvoiceType::Undefined;
        }
    };

    struct DocumentCurrencyCode final {
        static constexpr std::u8string_view id{u8"BT-5"};
        static constexpr std::u8string_view path{u8"cbc:DocumentCurrencyCode"};
        XDataTypes::Code type;
        ISO4217_CurrencyCode currencyCode{ISO4217_CurrencyCode::Unknown};

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxCurrencyCode final {
        static constexpr std::u8string_view id{u8"BT-6"};
        static constexpr std::u8string_view path{u8"cbc:TaxCurrencyCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxPointDate final {
        static constexpr std::u8string_view id{u8"BT-7"};
        static constexpr std::u8string_view path{u8"cbc:TaxPointDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoicePeriodDescriptionCode final {
        static constexpr std::u8string_view id{u8"BT-8"};
        static constexpr std::u8string_view path{u8"cbc:DescriptionCode"};
        PointDateCode type{PointDateCode::Undefined};

        [[nodiscard]] bool isValid() const {
            return type != PointDateCode::Undefined;
        }
    };

    struct DueDate final {
        static constexpr std::u8string_view id{u8"BT-9"};
        static constexpr std::u8string_view path{u8"cbc:DueDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerReference final {
        static constexpr std::u8string_view id{u8"BT-10"};
        static constexpr std::u8string_view path{u8"cbc:BuyerReference"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ProjectReference final {
        static constexpr std::u8string_view id{u8"BT-11"};
        static constexpr std::u8string_view outerPath{u8"cac:ProjectReference"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ContractDocumentReference final {
        static constexpr std::u8string_view id{u8"BT-12"};
        static constexpr std::u8string_view outerPath{u8"cac:ContractDocumentReference"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct OrderReference final {
        static constexpr std::u8string_view id{u8"BT-13"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct OrderReferenceSalesOrderID final {
        static constexpr std::u8string_view id{u8"BT-14"};
        static constexpr std::u8string_view path{u8"cbc:SalesOrderID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ReceiptDocumentReference final {
        static constexpr std::u8string_view id{u8"BT-15"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DespatchDocumentReference final {
        static constexpr std::u8string_view id{u8"BT-16"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct OriginatorDocumentReference final {
        static constexpr std::u8string_view id{u8"BT-17"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentReferenceIdentifier final {
        static constexpr std::u8string_view id{u8"BT-18"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentReferenceSchemaId final {
        static constexpr std::u8string_view id{u8"BT-18-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AccountingCost final {
        static constexpr std::u8string_view id{u8"BT-19"};
        static constexpr std::u8string_view path{u8"cbc:AccountingCost"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentTerms final {
        static constexpr std::u8string_view id{u8"BT-20"};
        static constexpr std::u8string_view path{u8"cbc:Note"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceNoteSubjectCode final {
        static constexpr std::u8string_view id{u8"BT-21"};
        static constexpr std::u8string_view path{u8"cbc:Note"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceNote final {
        static constexpr std::u8string_view id{u8"BT-22"};
        static constexpr std::u8string_view path{u8"cbc:Note"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BusinessProcessType final {
        static constexpr std::u8string_view id{u8"BT-23"};
        static constexpr std::u8string_view path{u8"cbc:ProfileID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SpecificationIdentifier final {
        static constexpr std::u8string_view id{u8"BT-24"};
        static constexpr std::u8string_view path{u8"cbc:CustomizationID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceDocumentReference final {
        static constexpr std::u8string_view id{u8"BT-25"};
        static constexpr std::u8string_view outerPath{u8"cac:InvoiceDocumentReference"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceDocumentReferenceIssueDate final {
        static constexpr std::u8string_view id{u8"BT-26"};
        static constexpr std::u8string_view path{u8"cbc:IssueDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerName final {
        static constexpr std::u8string_view id{u8"BT-27"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyLegalEntity"};
        static constexpr std::u8string_view path{u8"cbc:RegistrationName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerTradingName final {
        static constexpr std::u8string_view id{u8"BT-28"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyName"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerIdentifier final {
        static constexpr std::u8string_view id{u8"BT-29"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyIdentification"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-29-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerLegalIdentifier final {
        static constexpr std::u8string_view id{u8"BT-30"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerLegalIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-30-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerVATIdentifier final {
        static constexpr std::u8string_view id{u8"BT-31"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerTaxRegistrationIdentifier final {
        static constexpr std::u8string_view id{u8"BT-32"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerAdditionalLegalInformation final {
        static constexpr std::u8string_view id{u8"BT-33"};
        static constexpr std::u8string_view path{u8"cbc:CompanyLegalForm"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerElectronicAddress final {
        static constexpr std::u8string_view id{u8"BT-34"};
        static constexpr std::u8string_view path{u8"cbc:EndpointID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerElectronicAddressSchema final {
        static constexpr std::u8string_view id{u8"BT-34-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressStreetName final {
        static constexpr std::u8string_view id{u8"BT-35"};
        static constexpr std::u8string_view path{u8"cbc:StreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressAdditionalStreetName final {
        static constexpr std::u8string_view id{u8"BT-36"};
        static constexpr std::u8string_view path{u8"cbc:AdditionalStreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressAddressLine final {
        static constexpr std::u8string_view id{u8"BT-36"};
        static constexpr std::u8string_view path{u8"cbc:Line"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };


    struct SellerPostalAddressCityName final {
        static constexpr std::u8string_view id{u8"BT-37"};
        static constexpr std::u8string_view path{u8"cbc:CityName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressPostalZone final {
        static constexpr std::u8string_view id{u8"BT-38"};
        static constexpr std::u8string_view path{u8"cbc:PostalZone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressCountrySubentity final {
        static constexpr std::u8string_view id{u8"BT-39"};
        static constexpr std::u8string_view path{u8"cbc:CountrySubentity"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerPostalAddressCountryIdentificationCode final {
        /*
         * Ein Code, mit dem das Land bezeichnet wird.
         * Anmerkung: Die Liste der zulässigen Länder ist bei der ISO 3166-1 „Codes for the representation of names of
         * countries and their subdivisions“ erhältlich. Nur die Alpha-2-Darstellung darf verwendet werden.
         */
        static constexpr std::u8string_view id{u8"BT-40"};
        static constexpr std::u8string_view outerPath{u8"cac:Country"};
        static constexpr std::u8string_view path{u8"cbc:IdentificationCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerContactName final {
        static constexpr std::u8string_view id{u8"BT-41"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerContactTelephone final {
        static constexpr std::u8string_view id{u8"BT-42"};
        static constexpr std::u8string_view path{u8"cbc:Telephone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerContactEMail final {
        static constexpr std::u8string_view id{u8"BT-43"};
        static constexpr std::u8string_view path{u8"cbc:ElectronicMail"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerName final {
        static constexpr std::u8string_view id{u8"BT-44"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyLegalEntity"};
        static constexpr std::u8string_view path{u8"cbc:RegistrationName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerTradingName final {
        static constexpr std::u8string_view id{u8"BT-45"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyName"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerIdentifier final {
        static constexpr std::u8string_view id{u8"BT-46"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyIdentification"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-46-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerLegalRegistrationIdentifier final {
        static constexpr std::u8string_view id{u8"BT-47"};
        static constexpr std::u8string_view outerPath{u8"cbc:PartyLegalEntity"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerLegalRegistrationIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-47-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerVATIdentifier final {
        static constexpr std::u8string_view id{u8"BT-48"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyTaxScheme"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerElectronicAddress final {
        static constexpr std::u8string_view id{u8"BT-49"};
        static constexpr std::u8string_view path{u8"cbc:EndpointID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerElectronicAddressSchema final {
        static constexpr std::u8string_view id{u8"BT-49-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressStreetName final {
        static constexpr std::u8string_view id{u8"BT-50"};
        static constexpr std::u8string_view path{u8"cbc:StreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressAdditionalStreetName final {
        static constexpr std::u8string_view id{u8"BT-51"};
        static constexpr std::u8string_view path{u8"cbc:AdditionalStreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressAdditionalAddressLine final {
        static constexpr std::u8string_view id{u8"BT-163"};
        static constexpr std::u8string_view path{u8"cbc:Line"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressCityName final {
        static constexpr std::u8string_view id{u8"BT-52"};
        static constexpr std::u8string_view path{u8"cbc:CityName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressPostalZone final {
        static constexpr std::u8string_view id{u8"BT-53"};
        static constexpr std::u8string_view path{u8"cbc:PostalZone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressCountrySubentity final {
        static constexpr std::u8string_view id{u8"BT-54"};
        static constexpr std::u8string_view path{u8"cbc:CountrySubentity"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerAddressCountryIdentificationCode final {
        static constexpr std::u8string_view id{u8"BT-55"};
        static constexpr std::u8string_view outerPath{u8"cac:Country"};
        static constexpr std::u8string_view path{u8"cbc:IdentificationCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerContact final {
        static constexpr std::u8string_view id{u8"BT-56"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerContactTelephone final {
        static constexpr std::u8string_view id{u8"BT-57"};
        static constexpr std::u8string_view path{u8"cbc:Telephone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct BuyerContactEMail final {
        static constexpr std::u8string_view id{u8"BT-57"};
        static constexpr std::u8string_view path{u8"cbc:ElectronicMail"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeName final {
        static constexpr std::u8string_view id{u8"BT-59"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyName"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeIdentifier final {
        static constexpr std::u8string_view id{u8"BT-60"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyIdentification"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-60-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeLegalRegistrationIdentifier final {
        static constexpr std::u8string_view id{u8"BT-61"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyLegalEntity"};
        static constexpr std::u8string_view path{u8"cbc:CompanyID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeLegalRegistrationIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-61-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerTaxRepresentative final {
        static constexpr std::u8string_view id{u8"BT-62"};
        static constexpr std::u8string_view outerPath{u8"cac:PartyName"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct TaxRepresentativePostalAddressStreetName final {
        static constexpr std::u8string_view id{u8"BT-64"};
        static constexpr std::u8string_view path{u8"cbc:StreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressAdditionalStreetName final {
        static constexpr std::u8string_view id{u8"BT-65"};
        static constexpr std::u8string_view path{u8"cbc:AdditionalStreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressAddressLine final {
        static constexpr std::u8string_view id{u8"BT-164"};
        static constexpr std::u8string_view path{u8"cbc:Line"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressCity final {
        static constexpr std::u8string_view id{u8"BT-66"};
        static constexpr std::u8string_view path{u8"cbc:CityName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressPostCode final {
        static constexpr std::u8string_view id{u8"BT-67"};
        static constexpr std::u8string_view path{u8"cbc:PostalZone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressCountrySubentity final {
        static constexpr std::u8string_view id{u8"BT-68"};
        static constexpr std::u8string_view path{u8"cbc:CountrySubentity"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct TaxRepresentativePostalAddressCountryIdentificationCode final {
        static constexpr std::u8string_view id{u8"BT-69"};
        static constexpr std::u8string_view path{u8"cbc:IdentificationCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryName final {
        static constexpr std::u8string_view id{u8"BT-70"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryIdentifier final {
        static constexpr std::u8string_view id{u8"BT-71"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-71-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryDate final {
        static constexpr std::u8string_view id{u8"BT-72"};
        static constexpr std::u8string_view path{u8"cbc:ActualDeliveryDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoicePeriodStartDate final {
        static constexpr std::u8string_view id{u8"BT-73"};
        static constexpr std::u8string_view path{u8"cbc:StartDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoicePeriodEndDate final {
        static constexpr std::u8string_view id{u8"BT-74"};
        static constexpr std::u8string_view path{u8"cbc:EndDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationStreetName final {
        static constexpr std::u8string_view id{u8"BT-75"};
        static constexpr std::u8string_view path{u8"cbc:StreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationAdditionalStreetName final {
        static constexpr std::u8string_view id{u8"BT-76"};
        static constexpr std::u8string_view path{u8"cbc:AdditionalStreetName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationAdditionalAddressLine final {
        static constexpr std::u8string_view id{u8"BT-165"};
        static constexpr std::u8string_view path{u8"cbc:Line"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationCityName final {
        static constexpr std::u8string_view id{u8"BT-77"};
        static constexpr std::u8string_view path{u8"cbc:CityName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationPostalZone final {
        static constexpr std::u8string_view id{u8"BT-78"};
        static constexpr std::u8string_view path{u8"cbc:PostalZone"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationCountrySubentity final {
        static constexpr std::u8string_view id{u8"BT-79"};
        static constexpr std::u8string_view path{u8"cbc:CountrySubentity"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DeliveryLocationCountryCode final {
        static constexpr std::u8string_view id{u8"BT-80"};
        static constexpr std::u8string_view path{u8"cbc:IdentificationCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentMeansCode final {
        static constexpr std::u8string_view id{u8"BT-81"};
        static constexpr std::u8string_view path{u8"cbc:PaymentMeansCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentMeansText final {
        static constexpr std::u8string_view id{u8"BT-82"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentMeansPaymentId final {
        static constexpr std::u8string_view id{u8"BT-83"};
        static constexpr std::u8string_view path{u8"cbc:PaymentID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeFinancialAccountIdentifier final {
        static constexpr std::u8string_view id{u8"BT-84"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeFinancialAccountName final {
        static constexpr std::u8string_view id{u8"BT-85"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeFinancialAccountServiceProvider final {
        static constexpr std::u8string_view id{u8"BT-86"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentCardAccountPrimaryNumber final {
        static constexpr std::u8string_view id{u8"BT-87"};
        static constexpr std::u8string_view path{u8"cbc:PrimaryAccountNumberID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentCardAccountHolderName final {
        static constexpr std::u8string_view id{u8"BT-88"};
        static constexpr std::u8string_view path{u8"cbc:HolderName"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentMandateIdentifier final {
        static constexpr std::u8string_view id{u8"BT-89"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SellerBankAssignedCreditorIdentifier final {
        static constexpr std::u8string_view id{u8"BT-90"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PayeeBankAssignedCreditorIdentifier final {
        static constexpr std::u8string_view id{u8"BT-90"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct PaymentDebitAccountIdentifier final {
        static constexpr std::u8string_view id{u8"BT-91"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct AllowanceChargeMultiplier final {
        static constexpr std::u8string_view id{u8"BT-94"};
        static constexpr std::u8string_view path{u8"cbc:MultiplierFactorNumeric"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct AllowanceChargeTaxCategory final {
        static constexpr std::u8string_view id{u8"BT-95"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type{VATCategory::StandardRate};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct AllowanceChargeTaxCategoryPercentage final {
        static constexpr std::u8string_view id{u8"BT-96"};
        static constexpr std::u8string_view path{u8"cbc:Percent"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct AllowanceChargeReason final {
        static constexpr std::u8string_view id{u8"BT-97"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReason"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AllowanceChargeReasonCode final {
        static constexpr std::u8string_view id{u8"BT-98"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReason"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct DocLevelAllowanceChargePercentage final {
        static constexpr std::u8string_view id{u8"BT-101"};
        static constexpr std::u8string_view path{u8"cbc:MultiplierFactorNumeric"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct DocLevelAllowanceChargeTaxCategory final {
        static constexpr std::u8string_view id{u8"BT-102"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct DocLevelAllowanceChargeTaxRate final {
        static constexpr std::u8string_view id{u8"BT-103"};
        static constexpr std::u8string_view path{u8"cbc:Percent"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct DocLevelAllowanceChargeReason final {
        static constexpr std::u8string_view id{u8"BT-104"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReason"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct DocLevelAllowanceChargeReasonCode final {
        static constexpr std::u8string_view id{u8"BT-105"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReasonCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct VATCategoryRate final {
        static constexpr std::u8string_view id{u8"BT-119"};
        static constexpr std::u8string_view path{u8"cbc:Percent"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct VATExemptionReason final {
        static constexpr std::u8string_view id{u8"BT-120"};
        static constexpr std::u8string_view path{u8"cbc:TaxExemptionReason"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct VATExemptionReasonCode final {
        static constexpr std::u8string_view id{u8"BT-121"};
        static constexpr std::u8string_view path{u8"cbc:TaxExemptionReasonCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct SupportingDocumentReferenceIdentifier final {
        static constexpr std::u8string_view id{u8"BT-122"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentReferenceDescription final {
        static constexpr std::u8string_view id{u8"BT-123"};
        static constexpr std::u8string_view path{u8"cbc:DocumentDescription"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentExternalReference final {
        static constexpr std::u8string_view id{u8"BT-124"};
        static constexpr std::u8string_view path{u8"cbc:URI"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentAttached final {
        static constexpr std::u8string_view id{u8"BT-125"};
        static constexpr std::u8string_view path{u8"cbc:EmbeddedDocumentBinaryObject"};
        XDataTypes::BinaryObject type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct AdditionalDocumentAttachedMimeCode final {
        static constexpr std::u8string_view id{u8"BT-125-1"};
        static constexpr std::u8string_view attribute{u8"mimeCode"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct AdditionalDocumentAttachedFilename final {
        static constexpr std::u8string_view id{u8"BT-125-1"};
        static constexpr std::u8string_view attribute{u8"filename"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineIdentifier final {
        static constexpr std::u8string_view id{u8"BT-126"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineNote final {
        static constexpr std::u8string_view id{u8"BT-127"};
        static constexpr std::u8string_view path{u8"cbc:Note"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineObjectIdentifier final {
        static constexpr std::u8string_view id{u8"BT-128"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineObjectIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-128-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineQuantity final {
        static constexpr std::u8string_view id{u8"BT-129"};
        static constexpr std::u8string_view path{u8"cbc:InvoicedQuantity"};
        XDataTypes::Quantity type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineQuantityUnit final {
        static constexpr std::u8string_view id{u8"BT-130"};
        static constexpr std::u8string_view attribute{u8"unitCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineNetAmount final {
        static constexpr std::u8string_view id{u8"BT-131"};
        static constexpr std::u8string_view path{u8"cbc:LineExtensionAmount"};
        XDataTypes::Amount type;
        CurrencyAttribute currencyAttribute;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineOrderReference final {
        static constexpr std::u8string_view id{u8"BT-132"};
        static constexpr std::u8string_view path{u8"cbc:LineID"};
        XDataTypes::DocumentReference type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineAccountingCost final {
        static constexpr std::u8string_view id{u8"BT-133"};
        static constexpr std::u8string_view path{u8"cbc:AccountingCost"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLinePeriodStartDate final {
        static constexpr std::u8string_view id{u8"BT-134"};
        static constexpr std::u8string_view path{u8"cbc:StartDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLinePeriodEndDate final {
        static constexpr std::u8string_view id{u8"BT-135"};
        static constexpr std::u8string_view path{u8"cbc:EndDate"};
        XDataTypes::Date type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct InvoiceLineAllowancePercentage final {
        static constexpr std::u8string_view id{u8"BT-138"};
        static constexpr std::u8string_view path{u8"cbc:MultiplierFactorNumeric"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineAllowanceReason final {
        static constexpr std::u8string_view id{u8"BT-139"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReason"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineAllowanceReasonCode final {
        static constexpr std::u8string_view id{u8"BT-140"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReasonCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct InvoiceLineChargePercentage final {
        static constexpr std::u8string_view id{u8"BT-143"};
        static constexpr std::u8string_view path{u8"cbc:MultiplierFactorNumeric"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct InvoiceLineChargeReason final {
        static constexpr std::u8string_view id{u8"BT-144"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReason"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct InvoiceLineChargeReasonCode final {
        static constexpr std::u8string_view id{u8"BT-145"};
        static constexpr std::u8string_view path{u8"cbc:AllowanceChargeReasonCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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

    struct ItemBaseQuantity final {
        static constexpr std::u8string_view id{u8"BT-149"};
        static constexpr std::u8string_view path{u8"cbc:BaseQuantity"};
        XDataTypes::Quantity type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct ItemBaseQuantityCode final {
        static constexpr std::u8string_view id{u8"BT-150"};
        static constexpr std::u8string_view attribute{u8"unitCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemVATCategoryCode final {
        static constexpr std::u8string_view id{u8"BT-151"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        VATCategory type{VATCategory::StandardRate};

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct ItemVATRate final {
        static constexpr std::u8string_view id{u8"BT-152"};
        static constexpr std::u8string_view path{u8"cbc:Percent"};
        XDataTypes::Percentage type;

        [[nodiscard]] bool isValid() const {
            return true;
        }
    };

    struct ItemName final {
        static constexpr std::u8string_view id{u8"BT-153"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemDescription final {
        static constexpr std::u8string_view id{u8"BT-154"};
        static constexpr std::u8string_view path{u8"cbc:Description"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemSellerIdentifier final {
        static constexpr std::u8string_view id{u8"BT-155"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemBuyerIdentifier final {
        static constexpr std::u8string_view id{u8"BT-156"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemStandardIdentifier final {
        static constexpr std::u8string_view id{u8"BT-157"};
        static constexpr std::u8string_view path{u8"cbc:ID"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemStandardIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-157-1"};
        static constexpr std::u8string_view path{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemClassificationIdentifier final {
        static constexpr std::u8string_view id{u8"BT-158"};
        static constexpr std::u8string_view path{u8"cbc:ItemClassificationCode"};
        XDataTypes::Identifier type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemClassificationIdentifierSchema final {
        static constexpr std::u8string_view id{u8"BT-158-1"};
        static constexpr std::u8string_view attribute{u8"schemeID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemClassificationIdentifierSchemaVersion final {
        static constexpr std::u8string_view id{u8"BT-158-2"};
        static constexpr std::u8string_view attribute{u8"listVersionID"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemOriginCountryCode final {
        static constexpr std::u8string_view id{u8"BT-159"};
        static constexpr std::u8string_view path{u8"cbc:IdentificationCode"};
        XDataTypes::Code type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemAttributeName final {
        static constexpr std::u8string_view id{u8"BT-160"};
        static constexpr std::u8string_view path{u8"cbc:Name"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

    struct ItemAttributeValue final {
        static constexpr std::u8string_view id{u8"BT-161"};
        static constexpr std::u8string_view path{u8"cbc:Value"};
        XDataTypes::Text type;

        [[nodiscard]] bool isValid() const {
            return !type.content.empty();
        }
    };

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
