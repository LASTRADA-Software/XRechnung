#include "XRechnungSerializer.hpp"
#include "XRechnungCurrencyCode.hpp"
#include <array>

std::u8string serializeToXML(const XRechnung::Invoice &invoice) {
    XRechnung::Serializer::XmlWriter writer;
    return writer.getOutput();
}

using namespace XRechnung::Serializer;


XmlSaxSerializer XmlWriter::serializeChargeIndicator(const bool chargeIndicator) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = u8"cbc:ChargeIndicator", .content = chargeIndicator ? u8"true" : u8"false"});
    return serializer;
}

XmlWriter::XmlWriter() : pImpl(new XmlSaxSerializer()) {}

XmlSaxSerializer XmlWriter::serialize(const InvoiceNumber &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceIssueDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceTypeCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::to_string(static_cast<int>(obj.type)))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocumentCurrencyCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxCurrencyCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxPointDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoicePeriodDescriptionCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::to_string(static_cast<int>(obj.type)))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DueDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ProjectReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ContractDocumentReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const OrderReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const OrderReferenceSalesOrderID &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ReceiptDocumentReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DespatchDocumentReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const OriginatorDocumentReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AdditionalDocumentReferenceIdentifier &obj,
                                      const AdditionalDocumentReferenceSchemaId &schema) {

    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {AdditionalDocumentReferenceSchemaId::attribute, schema.type.content},
    };
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AccountingCost &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentTerms &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceNoteSubjectCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceNote &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BusinessProcessType &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SpecificationIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceDocumentReference &obj) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceDocumentReferenceIssueDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerName &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerTradingName &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer
XmlWriter::serialize(const SellerIdentifier &obj, const SellerIdentifierSchema &schema, const int indent) {
    XmlSaxSerializer innerSerializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[SellerIdentifierSchema::attribute] = schema.type.content;
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerLegalIdentifier &obj, const SellerLegalIdentifierSchema &schema) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[SellerLegalIdentifierSchema::attribute] = schema.type.content;
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SellerVATIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerTaxRegistrationIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerAdditionalLegalInformation &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerElectronicAddress &obj, const SellerElectronicAddressSchema &schema) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[SellerElectronicAddressSchema::attribute] = schema.type.content;
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressAdditionalStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressAddressLine &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressCityName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressPostalZone &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressCountrySubentity &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerPostalAddressCountryIdentificationCode &obj) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 5);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerContactName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerContactTelephone &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerContactEMail &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerName &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerTradingName &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerIdentifier &obj, const std::optional<BuyerIdentifierSchema> &schema,
                                      const int indent) {
    XmlParameterList xmlParameterList{};
    if (schema)
        xmlParameterList[BuyerIdentifierSchema::attribute] = schema.value().type.content;

    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent + 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer
XmlWriter::serialize(const BuyerLegalRegistrationIdentifier &obj, const BuyerLegalRegistrationIdentifierSchema &schema,
                     const int indent) {
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[BuyerLegalRegistrationIdentifierSchema::attribute] = schema.type.content;

    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent + 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerVATIdentifier &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerElectronicAddress &obj, const BuyerElectronicAddressSchema &schema) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[BuyerElectronicAddressSchema::attribute] = schema.type.content;
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressAdditionalStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressAdditionalAddressLine &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressCityName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressPostalZone &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressCountrySubentity &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerAddressCountryIdentificationCode &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerContact &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerContactTelephone &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BuyerContactEMail &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeName &obj) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeIdentifier &obj, const PayeeIdentifierSchema &schema) {
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[PayeeIdentifierSchema::attribute] = schema.type.content;

    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeLegalRegistrationIdentifier &obj,
                                      const PayeeLegalRegistrationIdentifierSchema &schema) {
    XmlParameterList xmlParameterList{
            {PayeeLegalRegistrationIdentifierSchema::attribute, schema.type.content},
    };
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerTaxRepresentative &obj) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerTaxRepresentativeVATIdentifier &obj) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.type.content});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressAdditionalStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressAddressLine &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressCity &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressPostCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressCountrySubentity &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const TaxRepresentativePostalAddressCountryIdentificationCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryIdentifier &obj, const DeliveryIdentifierSchema &schema) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[DeliveryIdentifierSchema::attribute] = schema.type.content;
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoicePeriodStartDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoicePeriodEndDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationAdditionalStreetName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationAdditionalAddressLine &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationCityName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationPostalZone &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationCountrySubentity &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DeliveryLocationCountryCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const XRechnung::PaymentMeansCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentMeansPaymentId &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const PaymentMeansText &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeFinancialAccountIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeFinancialAccountName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeFinancialAccountServiceProvider &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentCardAccountPrimaryNumber &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentCardAccountHolderName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentMandateIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SellerBankAssignedCreditorIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PayeeBankAssignedCreditorIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PaymentDebitAccountIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()}};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeBaseAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()}};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeMultiplier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeTaxCategory &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = allowedCodes.at(static_cast<int>(obj.type)).data()});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeTaxCategoryPercentage &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeReason &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AllowanceChargeReasonCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()}};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params=xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeBaseAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()}};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params=xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargePercentage &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeTaxCategory &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = allowedCodes.at(static_cast<int>(obj.type)).data()});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeTaxRate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeReason &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DocLevelAllowanceChargeReasonCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalNetAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalAllowanceAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalCharges &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalTaxExclusiveAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalVATAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalVATAmountCurrency &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalTaxInclusiveAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalPrepaidAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalPayableRoundingAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LegalMonetaryTotalPayableAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATTaxableAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATCategoryCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = allowedCodes.at(static_cast<int>(obj.type)).data()});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATCategoryRate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATExemptionReason &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATExemptionReasonCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SupportingDocumentReferenceIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AdditionalDocumentReferenceDescription &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const AdditionalDocumentExternalReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer
XmlWriter::serialize(const AdditionalDocumentAttached &obj, const AdditionalDocumentAttachedMimeCode &mimeCode, const AdditionalDocumentAttachedFilename &filename) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {AdditionalDocumentAttachedMimeCode::attribute, mimeCode.type.content},
            {AdditionalDocumentAttachedFilename::attribute, filename.type.content}};
    serializer.writeSingle({.tag = obj.path, .content = u8"", .params = xmlParameterList});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const InvoiceLineIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineNote &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer
XmlWriter::serialize(const InvoiceLineObjectIdentifier &obj, const InvoiceLineObjectIdentifierSchema &schema) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[InvoiceLineObjectIdentifierSchema::attribute] = schema.type.content;
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineQuantity &obj, const InvoiceLineQuantityUnit &unit) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {InvoiceLineQuantityUnit::attribute, unit.type.content},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineNetAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineOrderReference &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAccountingCost &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLinePeriodStartDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLinePeriodEndDate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAllowanceAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAllowanceBaseAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAllowancePercentage &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAllowanceReason &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineAllowanceReasonCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineChargeAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineChargeBaseAmount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineChargePercentage &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineChargeReason &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const InvoiceLineChargeReasonCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemNetPrice &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemPriceDiscount &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemGrossPrice &obj) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {CurrencyAttribute::path, ISO4217_toStdStringView(obj.currencyAttribute.currencyCode).data()},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content)), .params = xmlParameterList});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemBaseQuantity &obj, const ItemBaseQuantityCode &code) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{
            {ItemBaseQuantityCode::attribute, code.type.content},
    };
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const ItemVATCategoryCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = allowedCodes.at(static_cast<int>(obj.type))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemVATRate &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::format("{:.2f}", obj.type.content))});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemDescription &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemSellerIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemBuyerIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemStandardIdentifier &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemStandardIdentifierSchema &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer
XmlWriter::serialize(const ItemClassificationIdentifier &obj, const ItemClassificationIdentifierSchema &schema, const ItemClassificationIdentifierSchemaVersion &schemaVersion) {
    XmlSaxSerializer serializer{};
    XmlParameterList xmlParameterList{};
    if (schema.isValid())
        xmlParameterList[ItemClassificationIdentifierSchema::attribute] = schema.type.content;
    if (schemaVersion.isValid())
        xmlParameterList[ItemClassificationIdentifierSchemaVersion::attribute] = schemaVersion.type.content;

    serializer.writeSingle({.tag = obj.path, .content = obj.type.content, .params = xmlParameterList});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const ItemOriginCountryCode &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemAttributeName &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ItemAttributeValue &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_NOTE &obj) {
    XmlSaxSerializer serializer{};
    if (obj.subjectCode)
        serializer.writeSingle({.tag = obj.path, .content = serialize(obj.subjectCode.value()).output});
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PROCESS_CONTROL &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.specificationIdentifier), indent);
    if (obj.processType.isValid())
        serializer.write(serialize(obj.processType), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VAT_INFORMATION &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.documentReference), indent);
    if (obj.issueDate)
        serializer.write(serialize(obj.issueDate.value()), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VATTaxScheme &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.writeSingle({.tag = obj.path, .content = obj.id});

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.outerPath, .content = u8""});
    serializer.write(innerSerializer, indent + 1);
    serializer.resetIdent();
    serializer.setIdent(indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SELLER_POSTAL_ADDRESS &obj, const int indentLevel) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.address)
        serializer.write(serialize(obj.address.value()), indentLevel);
    if (obj.additional)
        serializer.write(serialize(obj.additional.value()), indentLevel);
    if (obj.additionalAddon)
        serializer.write(serialize(obj.additionalAddon.value()), indentLevel);
    if (obj.city.isValid())
        serializer.write(serialize(obj.city), indentLevel);
    if (obj.postalCode.isValid())
        serializer.write(serialize(obj.postalCode), indentLevel);
    if (obj.countrySubentity)
        serializer.write(serialize(obj.countrySubentity.value()), indentLevel);
    if (obj.countryCode.isValid())
        serializer.write(serialize(obj.countryCode), indentLevel);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SELLER_CONTACT &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), indent);
    serializer.write(serialize(obj.telephone), indent);
    serializer.write(serialize(obj.eMail), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SELLER &obj, const int indent) {
    const auto indentLevel = indent + 2;
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    XmlSaxSerializer innerSerializer{};
    innerSerializer.write({.tag = obj.subPath, .content = u8""});

    if (obj.electronicAddress.isValid())
        innerSerializer.write(serialize(obj.electronicAddress, obj.electronicAddressSchema), indentLevel);

    innerSerializer.write(serialize(obj.address, indentLevel + 1), indentLevel);

    if (obj.legalIdentifier || obj.vatIdentifier) {
        XmlSaxSerializer s{};
        s.write({.tag = u8"cac:PartyTaxScheme", .content = u8""});
        if (obj.legalIdentifier)
            s.write(serialize(obj.legalIdentifier.value(), SellerLegalIdentifierSchema()), indentLevel + 1);
        if (obj.vatIdentifier) {
            s.write(serialize(obj.vatIdentifier.value()), indentLevel + 1);
            s.write(serialize(VATTaxScheme(), indentLevel + 2), indentLevel + 1);
        }
        s.tagEnd();
        innerSerializer.write(s, indentLevel);
    }

    innerSerializer.write(serialize(obj.name, indentLevel + 1), indentLevel);

    if (obj.tradingName)
        innerSerializer.write(serialize(obj.tradingName.value(), indentLevel + 1), indentLevel);

    if (!obj.identifier.empty())
        for (auto &element: obj.identifier) {
            innerSerializer.write(serialize(element, SellerIdentifierSchema(), indentLevel + 1), indentLevel);
        }

    if (obj.taxRegistrationIdentifier)
        innerSerializer.write(serialize(obj.taxRegistrationIdentifier.value()), indentLevel);
    if (obj.additionalLegalInformation)
        innerSerializer.write(serialize(obj.additionalLegalInformation.value()), indentLevel);

    innerSerializer.write(serialize(obj.contact, indentLevel + 1), indentLevel);
    innerSerializer.setIdent(indent + 1);
    innerSerializer.tagEnd();

    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BUYER_POSTAL_ADDRESS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.address)
        serializer.write(serialize(obj.address.value()), indent);
    if (obj.additions)
        serializer.write(serialize(obj.additions.value()), indent);
    if (obj.additionsAddon)
        serializer.write(serialize(obj.additionsAddon.value()), indent);
    if (obj.city.isValid())
        serializer.write(serialize(obj.city), indent);
    if (obj.postalCode.isValid())
        serializer.write(serialize(obj.postalCode), indent);
    if (obj.countrySubdivision)
        serializer.write(serialize(obj.countrySubdivision.value()), indent);
    if (obj.countryCode.isValid())
        serializer.write(serialize(obj.countryCode, indent + 1), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BUYER_CONTACT &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    if (obj.contactPoint)
        serializer.write(serialize(obj.contactPoint.value()), indent);
    if (obj.telephone)
        serializer.write(serialize(obj.telephone.value()), indent);
    if (obj.email)
        serializer.write(serialize(obj.email.value()), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const BUYER &obj, const int indent) {
    const int indentLevel = indent + 2;
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    XmlSaxSerializer innerSerializer{};
    innerSerializer.write({.tag = obj.subPath, .content = u8""});

    if (obj.electronicAddress.isValid())
        innerSerializer.write(serialize(obj.electronicAddress, obj.electronicAddressSchema), indentLevel);
    if (obj.buyerId)
        innerSerializer.write(serialize(obj.buyerId.value(), std::nullopt, indentLevel + 1), indentLevel);

    innerSerializer.write(serialize(obj.address, indentLevel + 1), indentLevel);
    if (obj.contact)
        innerSerializer.write(serialize(obj.contact.value(), indentLevel + 1), indentLevel);
    if (obj.name)
        innerSerializer.write(serialize(obj.name.value(), indentLevel + 1), indentLevel);
    if (obj.tradingName)
        innerSerializer.write(serialize(obj.tradingName.value(), indentLevel + 1), indentLevel);

    if (obj.legalRegistrationId)
        innerSerializer.write(
                serialize(obj.legalRegistrationId.value(), BuyerLegalRegistrationIdentifierSchema(), indentLevel + 1),
                indentLevel);
    if (obj.vatIdentifier)
        innerSerializer.write(serialize(obj.vatIdentifier.value(), indentLevel + 1), indentLevel);
    innerSerializer.tagEnd();

    serializer.write(innerSerializer, indent + 1);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PAYEE &obj, const int indent) {
    XmlSaxSerializer innerSerializer{};
    innerSerializer.write({.tag = obj.path, .content = u8""});
    innerSerializer.write(serialize(obj.name), 1);
    if (obj.identifier)
        innerSerializer.write(serialize(obj.identifier.value(), PayeeIdentifierSchema()), indent + 1);

    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SELLER_TAX_REPRESENTATIVE_POSTAL_ADDRESS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.address)
        serializer.write(serialize(obj.address.value()), indent);
    if (obj.additional)
        serializer.write(serialize(obj.additional.value()), indent);
    if (obj.additionalAddon)
        serializer.write(serialize(obj.additionalAddon.value()), indent);
    if (obj.city)
        serializer.write(serialize(obj.city.value()), indent);
    if (obj.postalCode)
        serializer.write(serialize(obj.postalCode.value()), indent);
    if (obj.addressSubentity)
        serializer.write(serialize(obj.addressSubentity.value()), indent);
    serializer.write(serialize(obj.countryCode), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const SELLER_TAX_REPRESENTATIVE_PARTY &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.representative), indent);
    serializer.write(serialize(obj.vatIdentifier), indent);
    serializer.write(serialize(obj.address, indent + 1), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_PERIOD &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.startDate)
        serializer.write(serialize(obj.startDate.value()), indent);
    if (obj.endDate)
        serializer.write(serialize(obj.endDate.value()), indent);
    if (obj.descriptionCode)
        serializer.write(serialize(obj.descriptionCode.value()), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DELIVER_TO_ADDRESS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.address)
        serializer.write(serialize(obj.address.value()), indent);
    if (obj.additional)
        serializer.write(serialize(obj.additional.value()), indent);
    if (obj.additionalAddon)
        serializer.write(serialize(obj.additionalAddon.value()), indent);

    serializer.write(serialize(obj.deliveryCityName), indent);
    serializer.write(serialize(obj.deliveryPostalCode), indent);
    if (obj.locationCountrySubentity)
        serializer.write(serialize(obj.locationCountrySubentity.value()), indent);
    serializer.write(serialize(obj.deliveryCountryCode), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DELIVERY_INFORMATION &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    if (obj.name)
        serializer.write(serialize(obj.name.value()), indent);
    if (obj.identifier)
        serializer.write(serialize(obj.identifier.value(), DeliveryIdentifierSchema()), indent);
    if (obj.deliveryDate)
        serializer.write(serialize(obj.deliveryDate.value()), indent);
    if (obj.invoicePeriod)
        serializer.write(serialize(obj.invoicePeriod.value(), indent + 1), indent);
    if (obj.deliverToAddress)
        serializer.write(serialize(obj.deliverToAddress.value(), indent + 1), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const CREDIT_TRANSFER &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.accountIdentifier), indent);
    if (obj.accountName)
        serializer.write(serialize(obj.accountName.value()), indent);
    if (obj.accountServiceProvide)
        serializer.write(serialize(obj.accountServiceProvide.value()), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PAYMENT_CARD_INFORMATION &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.primaryNumber), indent);
    if (obj.holderName)
        serializer.write(serialize(obj.holderName.value()), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DIRECT_DEBIT &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.mandateIdentifier), indent);
    serializer.write(serialize(obj.assignedCreditorIdentifier), indent);
    serializer.write(serialize(obj.debitAccountIdentifier), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PAYMENT_INSTRUCTIONS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    if (obj.code.isValid())
        serializer.write(serialize(obj.code), indent);

    if (!obj.creditTransfer.empty())
        for (const auto &element: obj.creditTransfer) {
            serializer.write(serialize(element, indent + 1), indent);
        }

    if (obj.cardInformation)
        serializer.write(serialize(obj.cardInformation.value(), indent + 1), indent);
    if (obj.directDebit)
        serializer.write(serialize(obj.directDebit.value(), indent + 1), indent);

    if (obj.text)
        serializer.write(serialize(obj.text.value()), indent);
    if (obj.paymentId)
        serializer.write(serialize(obj.paymentId.value()), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DOCUMENT_ALLOWANCES &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), indent);

    if (obj.allowanceReason && !obj.allowanceReason.value().type.content.empty())
        serializer.write(serialize(obj.allowanceReason.value()), indent);
    if (obj.allowanceReasonCode && obj.allowanceReasonCode.value().isValid())
        serializer.write(serialize(obj.allowanceReasonCode.value()), indent);

    serializer.write(serialize(obj.percentage), indent);
    serializer.write(serialize(obj.amount), indent);

    if (obj.baseAmount && obj.baseAmount.value().isValid())
        serializer.write(serialize(obj.baseAmount.value()), indent);

    XmlSaxSerializer taxSerializer{};
    taxSerializer.write({.tag = u8"cac:TaxCategory", .content = u8""});
    taxSerializer.write(serialize(obj.taxCategoryCode), indent + 1);
    taxSerializer.write(serialize(obj.vatRate), indent + 1);
    taxSerializer.write(serialize(VATTaxScheme(), indent + 2), indent + 1);
    taxSerializer.tagEnd();

    serializer.write(taxSerializer, indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DOCUMENT_CHARGES &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), indent);

    if (obj.reasonCode)
    {
        serializer.write(serialize(obj.reasonCode.value()), indent);
    }
    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), indent);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), indent);

    serializer.write(serialize(obj.amount), indent);
    if (obj.baseAmount)
        serializer.write(serialize(obj.baseAmount.value()), indent);

    serializer.write(getTaxCategory(TaxParam<DocLevelAllowanceChargeTaxCategory>{.taxCode=obj.taxCategory, .taxRate={.type=obj.taxRate.type}}, indent + 1), indent);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const DOCUMENT_TOTALS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.netAmount), indent);

    if (obj.amountWithoutTax.isValid())
        serializer.write(serialize(obj.amountWithoutTax), indent);
    if (obj.amountWithTax.isValid())
        serializer.write(serialize(obj.amountWithTax), indent);
    if (obj.totalAllowanceAmount)
        serializer.write(serialize(obj.totalAllowanceAmount.value()), indent);
    if (obj.totalCharges)
        serializer.write(serialize(obj.totalCharges.value()), indent);

//    currently it looks like that this is not 100% correct we need to check in future if this will be supported
//    if (obj.taxAmount)
//        serializer.write(serialize(obj.taxAmount.value()), indent);

    if (obj.prepaidAmount)
        serializer.write(serialize(obj.prepaidAmount.value()), indent);
    if (obj.roundingAmount)
        serializer.write(serialize(obj.roundingAmount.value()), indent);
    if (obj.paymentAmountDue.isValid())
        serializer.write(serialize(obj.paymentAmountDue), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const VAT_BREAKDOWN &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.taxableAmount), indent);
    serializer.write(serialize(obj.taxAmount), indent);

    XmlSaxSerializer taxSerializer{};
    taxSerializer.write({.tag = u8"cac:TaxCategory", .content = u8""});
    taxSerializer.write(serialize(obj.categoryCode), indent);
    taxSerializer.write(serialize(obj.categoryRate), indent);
    taxSerializer.write(serialize(VATTaxScheme(), indent + 1), indent);
    taxSerializer.tagEnd();
    serializer.write(taxSerializer, 1);

    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), indent);
    if (obj.reasonCode)
        serializer.write(serialize(obj.reasonCode.value()), indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ADDITIONAL_SUPPORTING_DOCUMENTS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serialize(obj.referenceIdentifier), indent);

    if (obj.referenceDescription)
        serializer.write(serialize(obj.referenceDescription.value()), indent);
    if (obj.externalReference)
        serializer.write(serialize(obj.externalReference.value()), indent);
    if (obj.documentAttached)
        serializer.write(
                serialize(obj.documentAttached.value(),
                          AdditionalDocumentAttachedMimeCode(),
                          AdditionalDocumentAttachedFilename()),
                indent);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_LINE_PERIOD &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    if (obj.startDate)
        serializer.write(serialize(obj.startDate.value()), 1);
    if (obj.endDate)
        serializer.write(serialize(obj.endDate.value()), 1);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_LINE_ALLOWANCES &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), 3);

    serializer.write(serialize(obj.reasonCode), 3);
    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), 3);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), 3);

    serializer.write(serialize(obj.amount), 3);
    if (obj.baseAmount)
        serializer.write(serialize(obj.baseAmount.value()), 3);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_LINE_CHARGES &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), 1);

    serializer.write(serialize(obj.reasonCode), 1);
    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), 1);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), 1);

    serializer.write(serialize(obj.amount), 1);
    if (obj.baseAmount)
        serializer.write(serialize(obj.baseAmount.value()), 1);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const PRICE_DETAILS &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.netPrice), 3);
    if (obj.discount)
        serializer.write(serialize(obj.discount.value()), 3);
    if (obj.grossPrice)
        serializer.write(serialize(obj.grossPrice.value()), 3);
    if (obj.quantity && obj.quantityCode)
        serializer.write(serialize(obj.quantity.value(), obj.quantityCode.value()), 3);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const LINE_VAT_INFORMATION &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.categoryCode), 1);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), 1);
    serializer.write(serialize(VATTaxScheme(), 2), 1);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ITEM_ATTRIBUTES &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), 1);
    serializer.write(serialize(obj.value), 1);

    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const ITEM_INFORMATION &obj) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), 1);
    if (obj.description)
        serializer.write(serialize(obj.description.value()), 1);
    if (obj.sellerIdentifier)
        serializer.write(serialize(obj.sellerIdentifier.value()), 1);
    if (obj.buyerIdentifier)
        serializer.write(serialize(obj.buyerIdentifier.value()), 1);
    if (obj.standardIdentifier)
        serializer.write(serialize(obj.standardIdentifier.value()), 1);

    if (!obj.classificationIdentifier.empty())
        for (auto &element: obj.classificationIdentifier) {
            serializer.write(serialize(element, ItemClassificationIdentifierSchema(),
                                       ItemClassificationIdentifierSchemaVersion()),
                             1);
        }

    if (obj.itemOriginCountry)
        serializer.write(serialize(obj.itemOriginCountry.value()), 1);

    if (!obj.attributes.empty())
        for (auto &element: obj.attributes) {
            serializer.write(serialize(element), 1);
        }

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const ITEM_INFORMATION &obj, const LINE_VAT_INFORMATION &vat) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), 3);
    if (obj.description)
        serializer.write(serialize(obj.description.value()), 3);
    if (obj.sellerIdentifier)
        serializer.write(serialize(obj.sellerIdentifier.value()), 3);
    if (obj.buyerIdentifier)
        serializer.write(serialize(obj.buyerIdentifier.value()), 3);
    if (obj.standardIdentifier)
        serializer.write(serialize(obj.standardIdentifier.value()), 3);

    if (!obj.classificationIdentifier.empty())
        for (auto &element: obj.classificationIdentifier) {
            serializer.write(serialize(element, ItemClassificationIdentifierSchema(),
                                       ItemClassificationIdentifierSchemaVersion()),
                             3);
        }

    if (obj.itemOriginCountry)
        serializer.write(serialize(obj.itemOriginCountry.value()), 3);

    if (!obj.attributes.empty())
        for (auto &element: obj.attributes) {
            serializer.write(serialize(element), 3);
        }

    XmlSaxSerializer innerSerializer{};
    innerSerializer.write({.tag = vat.path, .content = u8""});

    innerSerializer.write(serialize(vat.categoryCode), 4);
    if (vat.percentage)
        innerSerializer.write(serialize(vat.percentage.value()), 4);
    innerSerializer.write(serialize(VATTaxScheme(), 5), 4);

    innerSerializer.tagEnd();

    serializer.write(innerSerializer, 3);
    serializer.tagEnd();
    return serializer;
}


XmlSaxSerializer XmlWriter::serialize(const INVOICE_LINE &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.identifier), indent);
    if (obj.note)
        serializer.write(serialize(obj.note.value()), indent);
    if (obj.objectIdentifier)
        serializer.write(serialize(obj.objectIdentifier.value(), InvoiceLineObjectIdentifierSchema()), indent);
    serializer.write(serialize(obj.quantity, obj.quantityUnit), indent);
    serializer.write(serialize(obj.netAmount), indent);
    if (obj.orderReference)
        serializer.write(serialize(obj.orderReference.value()), indent);
    if (obj.buyerAccountingReference)
        serializer.write(serialize(obj.buyerAccountingReference.value()), indent);
    if (obj.period.isValid())
        serializer.write(serialize(obj.period), indent);

    if (!obj.allowances.empty())
        for (auto &element: obj.allowances) {
            serializer.write(serialize(element), indent);
        }

    if (!obj.charges.empty())
        for (auto &element: obj.charges) {
            serializer.write(serialize(element), indent);
        }

    serializer.write(serialize(obj.itemInformation, obj.vatInformation), indent);
    serializer.write(serialize(obj.priceDetails), indent);

    if (!obj.subLines.empty())
        for (auto &element: obj.subLines) {
            serializer.write(serialize(element, indent + 1), indent);
        }

    if (obj.thirdPartyPayment)
        serializer.write(serialize(*obj.thirdPartyPayment, indent + 1), indent);

    serializer.tagEnd();
    return serializer;
}

std::u8string XmlWriter::serialize(const XRechnung::Invoice &invoice) {
    const int indentaionLevel = 1;
    XmlParameterList xmlParameterList{};
    for (const auto &xmlAttribute: invoice.getXMLAttributes()) {
        xmlParameterList[xmlAttribute.key] = xmlAttribute.value;
    }

    XmlSaxSerializer serializer{};
    serializer.write({.tag = u8"ubl:Invoice", .content = u8"", .params = xmlParameterList});

    const auto processControl = invoice.getProcessControl();
    serializer.write(serialize(processControl.specificationIdentifier), indentaionLevel);
    if (processControl.processType.isValid())
        serializer.write(serialize(processControl.processType), indentaionLevel);

    serializer.write(serialize(invoice.getInvoiceNumber()), indentaionLevel);
    serializer.write(serialize(invoice.getInvoiceIssueDate()), indentaionLevel);
    if (const auto dueDate = invoice.getDueDate(); dueDate.isValid())
        serializer.write(serialize(dueDate), indentaionLevel);

    const auto invoiceTypeCode = invoice.getInvoiceTypeCode();
    if (invoiceTypeCode.isValid())
        serializer.write(serialize(invoiceTypeCode), indentaionLevel);
    serializer.write(serialize(invoice.getInvoiceCurrencyCode()), indentaionLevel);

    const auto invoiceNote = invoice.getInvoiceNote();
    if (!invoiceNote.empty())
        for (const auto &element: invoiceNote) {
            serializer.write(serialize(element), indentaionLevel);
        }

    const auto accountingCurrencyCode = invoice.getAccountingCurrencyCode();
    if (accountingCurrencyCode.isValid())
        serializer.write(serialize(accountingCurrencyCode), indentaionLevel);

    const auto buyerReference = invoice.getBuyerReference();
    if (buyerReference.isValid())
        serializer.write(serialize(buyerReference), indentaionLevel);
    if (const auto taxPointDate = invoice.getTaxPointDate())
        serializer.write(serialize(taxPointDate.value()), indentaionLevel);
    if (const auto projectReference = invoice.getProjectReference())
        serializer.write(serialize(projectReference.value()), indentaionLevel);
    if (const auto contractReference = invoice.getContractReference())
        serializer.write(serialize(contractReference.value()), indentaionLevel);
    if (const auto orderReference = invoice.getOrderReference())
        serializer.write(serialize(orderReference.value()), indentaionLevel);
    if (const auto salesOrderReference = invoice.getSalesOrderReference())
        serializer.write(serialize(salesOrderReference.value()), indentaionLevel);
    if (const auto receivingAdviceReference = invoice.getReceivingAdviceReference())
        serializer.write(serialize(receivingAdviceReference.value()), indentaionLevel);
    if (const auto despatchAdviceReference = invoice.getDespatchAdviceReference())
        serializer.write(serialize(despatchAdviceReference.value()), indentaionLevel);
    if (const auto tenderOrIotReference = invoice.getTenderOrIotReference())
        serializer.write(serialize(tenderOrIotReference.value()), indentaionLevel);
    if (const auto invoicedObjectIdentifier = invoice.getInvoicedObjectIdentifier())
        serializer.write(serialize(invoicedObjectIdentifier.value(), {}), indentaionLevel);
    if (const auto buyerAccountingReference = invoice.getBuyerAccountingReference())
        serializer.write(serialize(buyerAccountingReference.value()), indentaionLevel);
    if (const auto paymentTerms = invoice.getPaymentTerms())
        serializer.write(serialize(paymentTerms.value()), indentaionLevel);

    const auto precedingInvoiceReference = invoice.getPrecedingInvoiceReference();
    if (!precedingInvoiceReference.empty())
        for (const auto &element: precedingInvoiceReference) {
            serializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }

    serializer.write(serialize(invoice.getSeller(), indentaionLevel + 1), indentaionLevel);
    serializer.write(serialize(invoice.getBuyer(), indentaionLevel + 1), indentaionLevel);

    if (const auto payee = invoice.getPayee())
        serializer.write(serialize(payee.value(), indentaionLevel + 1), indentaionLevel);
    if (const auto sellerTaxRepresentative = invoice.getSellerTaxRepresentative())
        serializer.write(serialize(sellerTaxRepresentative.value(), indentaionLevel + 1), indentaionLevel);
    if (const auto deliveryInformation = invoice.getDeliveryInformation())
        serializer.write(serialize(deliveryInformation.value(), indentaionLevel + 1), indentaionLevel);

    const auto paymentInstructions = invoice.getPaymentInstructions();
    if (paymentInstructions.isValid())
        serializer.write(serialize(paymentInstructions, indentaionLevel + 1), indentaionLevel);

    const auto documentAllowances = invoice.getDocumentAllowances();
    if (!documentAllowances.empty())
        for (const auto &element: documentAllowances) {
            serializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }

    const auto documentCharges = invoice.getDocumentCharges();
    if (!documentCharges.empty())
        for (const auto &element: documentCharges) {
            serializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }

    auto vatBreakdown = invoice.getVatBreakdown();
    if (!vatBreakdown.empty()) {
        double totalTaxableAmount{0};
        for (const auto &element: vatBreakdown) {
            totalTaxableAmount += element.taxAmount.type.content;
        }
        XmlSaxSerializer taxTotalSerializer{};
        taxTotalSerializer.write({.tag = u8"cac:TaxTotal", .content = u8""});
        taxTotalSerializer.write(serialize(LegalMonetaryTotalVATAmount{
                                         .type = {totalTaxableAmount},
                                         .currencyAttribute = {.currencyCode = invoice.getInvoiceCurrencyCode().currencyCode},
                                 }),
                                 indentaionLevel);
        // currently order matters so it is important that the total taxes comes as first child element

        for (auto &element: vatBreakdown) {
            taxTotalSerializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }
        taxTotalSerializer.tagEnd();
        serializer.write(taxTotalSerializer, indentaionLevel);
    }

    serializer.write(serialize(invoice.getDocumentTotals(), indentaionLevel + 1), indentaionLevel);

    const auto additionalSupportingDocuments = invoice.getAdditionalSupportingDocuments();
    if (!additionalSupportingDocuments.empty())
        for (const auto &element: additionalSupportingDocuments) {
            serializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }

    const auto invoiceLine = invoice.getInvoiceLine();
    if (!invoiceLine.empty())
        for (const auto &element: invoiceLine) {
            serializer.write(serialize(element, indentaionLevel + 1), indentaionLevel);
        }

    serializer.resetIdent();
    serializer.tagEnd();
    return serializer.output;
}

std::u8string XmlWriter::getOutput() const {
    if (pImpl)
        return pImpl->output;
    return {};
}

XmlSaxSerializer XmlWriter::serialize(const XMapping::SUB_INVOICE_LINE_PERIOD &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    if (obj.startDate)
        serializer.write(serialize(obj.startDate.value()), indent);
    if (obj.endDate)
        serializer.write(serialize(obj.endDate.value()), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_INVOICE_LINE_ALLOWANCES &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), indent);

    serializer.write(serialize(obj.reasonCode), indent);
    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), indent);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), indent);

    serializer.write(serialize(obj.amount), indent);
    if (obj.baseAmount)
        serializer.write(serialize(obj.baseAmount.value()), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_INVOICE_LINE_CHARGES &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});
    serializer.write(serializeChargeIndicator(obj.chargeIndicator), indent);

    serializer.write(serialize(obj.reasonCode), indent);
    if (obj.reason)
        serializer.write(serialize(obj.reason.value()), indent);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), indent);

    serializer.write(serialize(obj.amount), indent);
    if (obj.baseAmount)
        serializer.write(serialize(obj.baseAmount.value()), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_PRICE_DETAILS &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.netPrice), indent);
    if (obj.discount)
        serializer.write(serialize(obj.discount.value()), indent);
    if (obj.grossPrice)
        serializer.write(serialize(obj.grossPrice.value()), indent);
    if (obj.quantity && obj.quantityCode)
        serializer.write(serialize(obj.quantity.value(), obj.quantityCode.value()), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_LINE_VAT_INFORMATION &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.categoryCode), indent);
    if (obj.percentage)
        serializer.write(serialize(obj.percentage.value()), indent);
    serializer.write(serialize(VATTaxScheme(), indent + 1), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_ITEM_ATTRIBUTES &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), indent);
    serializer.write(serialize(obj.value), indent);

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_ITEM_INFORMATION &obj, const SUB_LINE_VAT_INFORMATION &vat, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.name), indent);
    if (obj.description)
        serializer.write(serialize(obj.description.value()), indent);
    if (obj.sellerIdentifier)
        serializer.write(serialize(obj.sellerIdentifier.value()), indent);
    if (obj.buyerIdentifier)
        serializer.write(serialize(obj.buyerIdentifier.value()), indent);
    if (obj.standardIdentifier)
        serializer.write(serialize(obj.standardIdentifier.value()), indent);

    if (!obj.classificationIdentifier.empty())
        for (auto &element: obj.classificationIdentifier) {
            serializer.write(serialize(element, ItemClassificationIdentifierSchema(),
                                       ItemClassificationIdentifierSchemaVersion()),
                             indent);
        }

    if (obj.itemOriginCountry)
        serializer.write(serialize(obj.itemOriginCountry.value()), indent);

    if (!obj.attributes.empty())
        for (auto &element: obj.attributes) {
            serializer.write(serialize(element, indent + 1), indent);
        }

    XmlSaxSerializer innerSerializer{};
    innerSerializer.write({.tag = vat.path, .content = u8""});

    innerSerializer.write(serialize(vat.categoryCode), indent + 1);
    if (vat.percentage)
        innerSerializer.write(serialize(vat.percentage.value()), indent + 1);
    innerSerializer.write(serialize(VATTaxScheme(), indent + 2), indent + 1);

    innerSerializer.tagEnd();

    serializer.write(innerSerializer, indent);
    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const SUB_INVOICE_LINE &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.identifier), indent);
    if (obj.note)
        serializer.write(serialize(obj.note.value()), indent);
    if (obj.objectIdentifier)
        serializer.write(serialize(obj.objectIdentifier.value(), InvoiceLineObjectIdentifierSchema()), indent);
    serializer.write(serialize(obj.quantity, obj.quantityUnit), indent);
    serializer.write(serialize(obj.netAmount), indent);
    if (obj.documentReference)
        serializer.write(serialize(obj.documentReference.value()), indent);
    if (obj.buyerAccountingReference)
        serializer.write(serialize(obj.buyerAccountingReference.value()), indent);
    if (obj.period && obj.period.value().isValid())
        serializer.write(serialize(*obj.period, indent + 1), indent);

    if (!obj.allowances.empty())
        for (auto &element: obj.allowances) {
            serializer.write(serialize(element, indent + 1), indent);
        }

    if (!obj.charges.empty())
        for (auto &element: obj.charges) {
            serializer.write(serialize(element, indent + 1), indent);
        }

    serializer.write(serialize(obj.itemInformation, obj.vatInformation, indent + 1), indent);
    serializer.write(serialize(obj.priceDetails, indent + 1), indent);

    if (!obj.subLines.empty())
        for (auto &element: obj.subLines) {
            serializer.write(serialize(element, indent + 2), indent + 1);
        }

    serializer.tagEnd();
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const THIRD_PARTY_PAYMENT &obj, const int indent) {
    XmlSaxSerializer serializer{};
    serializer.write({.tag = obj.path, .content = u8""});

    serializer.write(serialize(obj.paymentType), indent + 1);
    serializer.write(serialize(obj.amount), indent + 1);
    serializer.write(serialize(obj.description), indent + 1);

    serializer.tagEnd();
    return serializer;
}
XmlSaxSerializer XmlWriter::serialize(const XMapping::ThirdPartyPaymentType &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}
XmlSaxSerializer XmlWriter::serialize(const XMapping::ThirdPartyPaymentAmount &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = stdStringToU8Str(std::to_string(obj.type.content))});
    return serializer;
}

XmlSaxSerializer XmlWriter::serialize(const XMapping::ThirdPartyPaymentDescription &obj) {
    XmlSaxSerializer serializer{};
    serializer.writeSingle({.tag = obj.path, .content = obj.type.content});
    return serializer;
}
