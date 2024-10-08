#pragma once

#include <format>
#include <memory>
#include <unordered_map>

#include "XRechnung.hpp"
#include "XRechnungMapping.hpp"

namespace XRechnung {
    namespace Serializer {
        using XmlParameterList = std::unordered_map<std::u8string_view, std::u8string>;

        template<typename T>
        struct TaxParam {
            T taxCode{};
            VATCategoryRate taxRate{};
        };

        struct XMLParam {
            std::u8string_view tag{};
            std::u8string_view content{};
            XmlParameterList params{};
        };

        struct XmlSaxSerializer {
            std::u8string output;
            int indentationLevel = 0;
            std::u8string_view currentTag;

            using XmlParameterList = std::unordered_map<std::u8string_view, std::u8string>;

            template<typename... Args>
            void singleLineComment(std::format_string<Args...> comment, Args &&...args) {
                singleLineComment(std::format(comment, std::forward<Args>(args)...));
            }

            void singleLineComment(std::u8string_view comment) {
                xmlIndent();
                output += u8"<!-- ";
                output += comment;
                output += u8" -->\n";
            }

            void tagStart(std::u8string_view tag, XmlParameterList const &params = {}) {
                currentTag = tag;

                output += u8"<";
                output += currentTag;

                for (auto const &[key, value]: params) {
                    output += u8" ";
                    output += key;
                    output += u8"=\"";
                    output += value;// TODO: escape at least double quotes
                    output += u8"\"";
                }

                output += u8">";
            }

            void tagEnd() {
                --indentationLevel;
                xmlIndent();
                output += u8"</";
                output += currentTag;
                output += u8">\n";
            }

            void xmlIndent() {
                for (int idx = 0; idx < indentationLevel; ++idx) {
                    output += u8"  ";
                }
            }

            void resetIdent() {
                indentationLevel = 0;
            }

            void setIdent(const int level) {
                indentationLevel = level;
            }

            void write(const XMLParam &param) {
                tagStart(param.tag, param.params);
                if (!param.content.empty())
                    output += param.content;
            }

            void write(const XmlSaxSerializer &serializer, const int indentation) {
                indentationLevel = indentation;
                const auto content = serializer.output;
                if (!content.empty()) {
                    if (*(output.end() - 1) != u8'\n')
                        output += u8"\n";
                    xmlIndent();
                    output += content;
                }
            }

            void writeSingle(const XMLParam &param) {
                tagStart(param.tag, param.params);
                if (!param.content.empty())
                    output += param.content;
                tagEnd();
            }
        };

        class XmlWriter {
            using XmlParameterList = XmlParameterList;

        private:
            std::unique_ptr<XmlSaxSerializer> pImpl;

            XmlSaxSerializer serializeChargeIndicator(const bool chargeIndicator);

        public:
            XmlWriter();

            ~XmlWriter() = default;

            XmlSaxSerializer serialize(const InvoiceNumber &obj);

            XmlSaxSerializer serialize(const InvoiceIssueDate &obj);

            XmlSaxSerializer serialize(const InvoiceTypeCode &obj);

            XmlSaxSerializer serialize(const DocumentCurrencyCode &obj);

            XmlSaxSerializer serialize(const TaxCurrencyCode &obj);

            XmlSaxSerializer serialize(const TaxPointDate &obj);

            XmlSaxSerializer serialize(const InvoicePeriodDescriptionCode &obj);

            XmlSaxSerializer serialize(const DueDate &obj);

            XmlSaxSerializer serialize(const BuyerReference &obj);

            XmlSaxSerializer serialize(const ProjectReference &obj);

            XmlSaxSerializer serialize(const ContractDocumentReference &obj);

            XmlSaxSerializer serialize(const OrderReference &obj);

            XmlSaxSerializer serialize(const OrderReferenceSalesOrderID &obj);

            XmlSaxSerializer serialize(const ReceiptDocumentReference &obj);

            XmlSaxSerializer serialize(const DespatchDocumentReference &obj);

            XmlSaxSerializer serialize(const OriginatorDocumentReference &obj);

            XmlSaxSerializer serialize(const AdditionalDocumentReferenceIdentifier &obj,
                                       const AdditionalDocumentReferenceSchemaId &schema);

            XmlSaxSerializer serialize(const AccountingCost &obj);

            XmlSaxSerializer serialize(const PaymentTerms &obj);

            XmlSaxSerializer serialize(const InvoiceNoteSubjectCode &obj);

            XmlSaxSerializer serialize(const InvoiceNote &obj);

            XmlSaxSerializer serialize(const BusinessProcessType &obj);

            XmlSaxSerializer serialize(const SpecificationIdentifier &obj);

            XmlSaxSerializer serialize(const InvoiceDocumentReference &obj);

            XmlSaxSerializer serialize(const InvoiceDocumentReferenceIssueDate &obj);

            XmlSaxSerializer serialize(const SellerName &obj, int indent);

            XmlSaxSerializer serialize(const SellerTradingName &obj, int indent);

            XmlSaxSerializer serialize(const SellerIdentifier &obj, const SellerIdentifierSchema &schema, int indent);

            XmlSaxSerializer serialize(const SellerLegalIdentifier &obj, const SellerLegalIdentifierSchema &schema);

            XmlSaxSerializer serialize(const SellerVATIdentifier &obj);

            XmlSaxSerializer serialize(const SellerTaxRegistrationIdentifier &obj);

            XmlSaxSerializer serialize(const SellerAdditionalLegalInformation &obj);

            XmlSaxSerializer serialize(const SellerElectronicAddress &obj, const SellerElectronicAddressSchema &schema);

            XmlSaxSerializer serialize(const SellerPostalAddressStreetName &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressAdditionalStreetName &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressAddressLine &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressCityName &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressPostalZone &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressCountrySubentity &obj);

            XmlSaxSerializer serialize(const SellerPostalAddressCountryIdentificationCode &obj);

            XmlSaxSerializer serialize(const SellerContactName &obj);

            XmlSaxSerializer serialize(const SellerContactTelephone &obj);

            XmlSaxSerializer serialize(const SellerContactEMail &obj);

            XmlSaxSerializer serialize(const BuyerName &obj, int indent);

            XmlSaxSerializer serialize(const BuyerTradingName &obj, int indent);

            XmlSaxSerializer
            serialize(const BuyerIdentifier &obj, const std::optional<BuyerIdentifierSchema> &schema, int indent);

            XmlSaxSerializer
            serialize(const BuyerLegalRegistrationIdentifier &obj, const BuyerLegalRegistrationIdentifierSchema &schema,
                      int indent);

            XmlSaxSerializer serialize(const BuyerVATIdentifier &obj, int indent);

            XmlSaxSerializer serialize(const BuyerElectronicAddress &obj, const BuyerElectronicAddressSchema &schema);

            XmlSaxSerializer serialize(const BuyerAddressStreetName &obj);

            XmlSaxSerializer serialize(const BuyerAddressAdditionalStreetName &obj);

            XmlSaxSerializer serialize(const BuyerAddressAdditionalAddressLine &obj);

            XmlSaxSerializer serialize(const BuyerAddressCityName &obj);

            XmlSaxSerializer serialize(const BuyerAddressPostalZone &obj);

            XmlSaxSerializer serialize(const BuyerAddressCountrySubentity &obj);

            XmlSaxSerializer serialize(const BuyerAddressCountryIdentificationCode &obj, int indent);

            XmlSaxSerializer serialize(const BuyerContact &obj);

            XmlSaxSerializer serialize(const BuyerContactTelephone &obj);

            XmlSaxSerializer serialize(const BuyerContactEMail &obj);

            XmlSaxSerializer serialize(const PayeeName &obj);

            XmlSaxSerializer serialize(const PayeeIdentifier &obj, const PayeeIdentifierSchema &schema);

            XmlSaxSerializer serialize(const PayeeLegalRegistrationIdentifier &obj,
                                       const PayeeLegalRegistrationIdentifierSchema &schema);

            XmlSaxSerializer serialize(const SellerTaxRepresentative &obj);

            XmlSaxSerializer serialize(const SellerTaxRepresentativeVATIdentifier &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressStreetName &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressAdditionalStreetName &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressAddressLine &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressCity &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressPostCode &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressCountrySubentity &obj);

            XmlSaxSerializer serialize(const TaxRepresentativePostalAddressCountryIdentificationCode &obj);

            XmlSaxSerializer serialize(const DeliveryName &obj);

            XmlSaxSerializer serialize(const DeliveryIdentifier &obj, const DeliveryIdentifierSchema &schema);

            XmlSaxSerializer serialize(const DeliveryDate &obj);

            XmlSaxSerializer serialize(const InvoicePeriodStartDate &obj);

            XmlSaxSerializer serialize(const InvoicePeriodEndDate &obj);

            XmlSaxSerializer serialize(const DeliveryLocationStreetName &obj);

            XmlSaxSerializer serialize(const DeliveryLocationAdditionalStreetName &obj);

            XmlSaxSerializer serialize(const DeliveryLocationAdditionalAddressLine &obj);

            XmlSaxSerializer serialize(const DeliveryLocationCityName &obj);

            XmlSaxSerializer serialize(const DeliveryLocationPostalZone &obj);

            XmlSaxSerializer serialize(const DeliveryLocationCountrySubentity &obj);

            XmlSaxSerializer serialize(const DeliveryLocationCountryCode &obj);

            XmlSaxSerializer serialize(const XRechnung::PaymentMeansCode &obj);

            XmlSaxSerializer serialize(const PaymentMeansPaymentId &obj);

            XmlSaxSerializer serialize(const PaymentMeansText &obj);

            XmlSaxSerializer serialize(const PayeeFinancialAccountIdentifier &obj);

            XmlSaxSerializer serialize(const PayeeFinancialAccountName &obj);

            XmlSaxSerializer serialize(const PayeeFinancialAccountServiceProvider &obj);

            XmlSaxSerializer serialize(const PaymentCardAccountPrimaryNumber &obj);

            XmlSaxSerializer serialize(const PaymentCardAccountHolderName &obj);

            XmlSaxSerializer serialize(const PaymentMandateIdentifier &obj);

            XmlSaxSerializer serialize(const SellerBankAssignedCreditorIdentifier &obj);

            XmlSaxSerializer serialize(const PaymentDebitAccountIdentifier &obj);

            XmlSaxSerializer serialize(const AllowanceChargeAmount &obj);

            XmlSaxSerializer serialize(const AllowanceChargeBaseAmount &obj);

            XmlSaxSerializer serialize(const AllowanceChargeMultiplier &obj);

            XmlSaxSerializer serialize(const AllowanceChargeTaxCategory &obj);

            XmlSaxSerializer serialize(const AllowanceChargeTaxCategoryPercentage &obj);

            XmlSaxSerializer serialize(const AllowanceChargeReason &obj);

            XmlSaxSerializer serialize(const AllowanceChargeReasonCode &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeAmount &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeBaseAmount &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargePercentage &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeTaxCategory &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeTaxRate &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeReason &obj);

            XmlSaxSerializer serialize(const DocLevelAllowanceChargeReasonCode &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalNetAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalAllowanceAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalCharges &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalTaxExclusiveAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalVATAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalVATAmountCurrency &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalTaxInclusiveAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalPrepaidAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalPayableRoundingAmount &obj);

            XmlSaxSerializer serialize(const LegalMonetaryTotalPayableAmount &obj);

            XmlSaxSerializer serialize(const VATTaxableAmount &obj);

            XmlSaxSerializer serialize(const VATAmount &obj);

            XmlSaxSerializer serialize(const VATCategoryCode &obj);

            XmlSaxSerializer serialize(const VATCategoryRate &obj);

            XmlSaxSerializer serialize(const VATExemptionReason &obj);

            XmlSaxSerializer serialize(const VATExemptionReasonCode &obj);

            XmlSaxSerializer serialize(const SupportingDocumentReferenceIdentifier &obj);

            XmlSaxSerializer serialize(const AdditionalDocumentReferenceDescription &obj);

            XmlSaxSerializer serialize(const AdditionalDocumentExternalReference &obj);

            XmlSaxSerializer
            serialize(const AdditionalDocumentAttached &obj, const AdditionalDocumentAttachedMimeCode &mimeCode, const AdditionalDocumentAttachedFilename &filename);

            XmlSaxSerializer serialize(const InvoiceLineIdentifier &obj);

            XmlSaxSerializer serialize(const InvoiceLineNote &obj);

            XmlSaxSerializer
            serialize(const InvoiceLineObjectIdentifier &obj, const InvoiceLineObjectIdentifierSchema &schema);

            XmlSaxSerializer serialize(const InvoiceLineQuantity &obj, const InvoiceLineQuantityUnit &unit);

            XmlSaxSerializer serialize(const InvoiceLineNetAmount &obj);

            XmlSaxSerializer serialize(const InvoiceLineOrderReference &obj);

            XmlSaxSerializer serialize(const InvoiceLineAccountingCost &obj);

            XmlSaxSerializer serialize(const InvoiceLinePeriodStartDate &obj);

            XmlSaxSerializer serialize(const InvoiceLinePeriodEndDate &obj);

            XmlSaxSerializer serialize(const InvoiceLineAllowanceAmount &obj);

            XmlSaxSerializer serialize(const InvoiceLineAllowanceBaseAmount &obj);

            XmlSaxSerializer serialize(const InvoiceLineAllowancePercentage &obj);

            XmlSaxSerializer serialize(const InvoiceLineAllowanceReason &obj);

            XmlSaxSerializer serialize(const InvoiceLineAllowanceReasonCode &obj);

            XmlSaxSerializer serialize(const InvoiceLineChargeAmount &obj);

            XmlSaxSerializer serialize(const InvoiceLineChargeBaseAmount &obj);

            XmlSaxSerializer serialize(const InvoiceLineChargePercentage &obj);

            XmlSaxSerializer serialize(const InvoiceLineChargeReason &obj);

            XmlSaxSerializer serialize(const InvoiceLineChargeReasonCode &obj);

            XmlSaxSerializer serialize(const ItemNetPrice &obj);

            XmlSaxSerializer serialize(const ItemPriceDiscount &obj);

            XmlSaxSerializer serialize(const ItemGrossPrice &obj);

            XmlSaxSerializer serialize(const ItemBaseQuantity &obj, const ItemBaseQuantityCode &code);

            XmlSaxSerializer serialize(const ItemVATCategoryCode &obj);

            XmlSaxSerializer serialize(const ItemVATRate &obj);

            XmlSaxSerializer serialize(const ItemName &obj);

            XmlSaxSerializer serialize(const ItemDescription &obj);

            XmlSaxSerializer serialize(const ItemSellerIdentifier &obj);

            XmlSaxSerializer serialize(const ItemBuyerIdentifier &obj);

            XmlSaxSerializer serialize(const ItemStandardIdentifier &obj);

            XmlSaxSerializer serialize(const ItemStandardIdentifierSchema &obj);

            XmlSaxSerializer
            serialize(const ItemClassificationIdentifier &obj, const ItemClassificationIdentifierSchema &schema, const ItemClassificationIdentifierSchemaVersion &schemaVersion);

            XmlSaxSerializer serialize(const ItemOriginCountryCode &obj);

            XmlSaxSerializer serialize(const ItemAttributeName &obj);

            XmlSaxSerializer serialize(const ItemAttributeValue &obj);

            XmlSaxSerializer serialize(const INVOICE_NOTE &obj);

            XmlSaxSerializer serialize(const PROCESS_CONTROL &obj, int indent);

            XmlSaxSerializer serialize(const VAT_INFORMATION &obj, int indent);

            XmlSaxSerializer serialize(const VATTaxScheme &obj, int indent);

            XmlSaxSerializer serialize(const SELLER_POSTAL_ADDRESS &obj, int indentLevel);

            XmlSaxSerializer serialize(const SELLER_CONTACT &obj, int indent);

            XmlSaxSerializer serialize(const SELLER &obj, int indent);

            XmlSaxSerializer serialize(const BUYER_POSTAL_ADDRESS &obj, int indent);

            XmlSaxSerializer serialize(const BUYER_CONTACT &obj, int indent);

            XmlSaxSerializer serialize(const BUYER &obj, int indent);

            XmlSaxSerializer serialize(const PAYEE &obj, int indent);

            XmlSaxSerializer serialize(const SELLER_TAX_REPRESENTATIVE_POSTAL_ADDRESS &obj, int indent);

            XmlSaxSerializer serialize(const SELLER_TAX_REPRESENTATIVE_PARTY &obj, int indent);

            XmlSaxSerializer serialize(const INVOICE_PERIOD &obj, int indent);

            XmlSaxSerializer serialize(const DELIVER_TO_ADDRESS &obj, int indent);

            XmlSaxSerializer serialize(const DELIVERY_INFORMATION &obj, int indent);

            XmlSaxSerializer serialize(const CREDIT_TRANSFER &obj, int indent);

            XmlSaxSerializer serialize(const PAYMENT_CARD_INFORMATION &obj, int indent);

            XmlSaxSerializer serialize(const DIRECT_DEBIT &obj, int indent);

            XmlSaxSerializer serialize(const PAYMENT_INSTRUCTIONS &obj, int indent);

            XmlSaxSerializer serialize(const DOCUMENT_ALLOWANCES &obj, int indent);

            XmlSaxSerializer serialize(const DOCUMENT_CHARGES &obj, int indent);

            XmlSaxSerializer serialize(const DOCUMENT_TOTALS &obj, int indent);

            XmlSaxSerializer serialize(const VAT_BREAKDOWN &obj, int indent);

            XmlSaxSerializer serialize(const ADDITIONAL_SUPPORTING_DOCUMENTS &obj, int indent);

            XmlSaxSerializer serialize(const XMapping::SUB_INVOICE_LINE_PERIOD &obj, int indent);

            XmlSaxSerializer serialize(const INVOICE_LINE_PERIOD &obj);

            XmlSaxSerializer serialize(const SUB_INVOICE_LINE_ALLOWANCES &obj, int indent);

            XmlSaxSerializer serialize(const INVOICE_LINE_ALLOWANCES &obj);

            XmlSaxSerializer serialize(const SUB_INVOICE_LINE_CHARGES &obj, int indent);

            XmlSaxSerializer serialize(const INVOICE_LINE_CHARGES &obj);

            XmlSaxSerializer serialize(const SUB_PRICE_DETAILS &obj, int indent);

            XmlSaxSerializer serialize(const PRICE_DETAILS &obj);

            XmlSaxSerializer serialize(const SUB_LINE_VAT_INFORMATION &obj, int indent);

            XmlSaxSerializer serialize(const LINE_VAT_INFORMATION &obj);

            XmlSaxSerializer serialize(const SUB_ITEM_ATTRIBUTES &obj, int indent);

            XmlSaxSerializer serialize(const ITEM_ATTRIBUTES &obj);

            XmlSaxSerializer serialize(const ITEM_INFORMATION &obj);

            XmlSaxSerializer serialize(const SUB_ITEM_INFORMATION &obj, const SUB_LINE_VAT_INFORMATION &vat, const int indent);

            XmlSaxSerializer serialize(const ITEM_INFORMATION &obj, const LINE_VAT_INFORMATION &vat);

            XmlSaxSerializer serialize(const SUB_INVOICE_LINE &obj, int indent);

            XmlSaxSerializer serialize(const INVOICE_LINE &obj, int indent);

            XmlSaxSerializer serialize(const ThirdPartyPaymentType &obj);

            XmlSaxSerializer serialize(const ThirdPartyPaymentAmount &obj);

            XmlSaxSerializer serialize(const ThirdPartyPaymentDescription &obj);

            XmlSaxSerializer serialize(const THIRD_PARTY_PAYMENT &obj, int indent);

            template<typename T>
            XmlSaxSerializer getTaxCategory(const TaxParam<T> &obj, int indent) {
                XmlSaxSerializer taxSerializer{};
                taxSerializer.write({.tag = u8"cac:TaxCategory", .content = u8""});
                taxSerializer.write(serialize(obj.taxCode), indent);
                taxSerializer.write(serialize(obj.taxRate), indent);
                taxSerializer.write(serialize(XMapping::VATTaxScheme(), indent + 1), indent);
                taxSerializer.tagEnd();
                return taxSerializer;
            }

            std::u8string serialize(const XRechnung::Invoice &invoice);

            std::u8string getOutput() const;
        };
    }// namespace Serializer
}// namespace XRechnung
