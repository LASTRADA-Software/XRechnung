#include "XRechnung.hpp"
#include "XRechnungAllowanceChargeCode.hpp"
#include "XRechnungChargeReasonCode.hpp"
#include "XRechnungEASCode.hpp"
#include "XRechnungMapping.hpp"
#include "XRechnungMeasureUnit.hpp"

#include <algorithm>

using namespace XMapping;
using namespace XRechnungUtils;


void XRechnung::Invoice::setInvoiceNumber(std::u8string number) noexcept {
    invoiceNumber = InvoiceNumber{std::move(number)};
}

void XRechnung::Invoice::setIssueDate(std::u8string dateStr) noexcept {
    invoiceIssueDate = InvoiceIssueDate{.type = {std::move(dateStr)}};
}

void XRechnung::Invoice::setInvoiceTypeCode(const InvoiceType type) noexcept {
    invoiceTypeCode.type = type;
}

void XRechnung::Invoice::setCurrencyCode(const ISO4217_CurrencyCode currencyCode) {
    const auto crrncyCode = std::u8string{ISO4217_toStdStringView(currencyCode)};
    invoiceCurrencyCode = DocumentCurrencyCode{.type = {
                                                       .id = crrncyCode,
                                                       .content = crrncyCode,
                                               },
                                               .currencyCode = currencyCode};
}

void XRechnung::Invoice::setAccountingCurrencyCode(const ISO4217_CurrencyCode currencyCode) {
    accountingCurrencyCode = TaxCurrencyCode{.type = {std::u8string{ISO4217_toStdStringView(currencyCode)}}};
}

void XRechnung::Invoice::setTaxPointDate(std::u8string dateStr) {
    taxPointDate = TaxPointDate{.type = {std::move(dateStr)}};
}

void XRechnung::Invoice::setPeriodDescriptionCode(const PointDateCode dateCode) {
    if (dateCode == PointDateCode::Undefined)
        return;

    if (deliveryInformation && deliveryInformation.value().invoicePeriod)
        deliveryInformation.value().invoicePeriod.value().descriptionCode = InvoicePeriodDescriptionCode{.type = dateCode};
    else if (deliveryInformation && !deliveryInformation.value().invoicePeriod) {
        auto invoicePeriod = INVOICE_PERIOD();
        invoicePeriod.descriptionCode = InvoicePeriodDescriptionCode{.type = dateCode};
        deliveryInformation.value().invoicePeriod = std::move(invoicePeriod);
    } else {
        auto deliveryInfo = DELIVERY_INFORMATION();
        auto invoicePeriod = INVOICE_PERIOD();
        invoicePeriod.descriptionCode = InvoicePeriodDescriptionCode{.type = dateCode};
        deliveryInfo.invoicePeriod = std::move(invoicePeriod);
        deliveryInformation = std::move(deliveryInfo);
    }
}

void XRechnung::Invoice::setDueDate(std::u8string dateStr) {
    dueDate = DueDate{.type = {std::move(dateStr)}};
}

void XRechnung::Invoice::setBuyerReference(std::u8string reference) {
    buyerReference = BuyerReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setProjectReference(std::u8string reference) {
    projectReference = ProjectReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setContractReference(std::u8string reference) {
    contractReference = ContractDocumentReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setOrderReference(std::u8string reference) {
    orderReference = OrderReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setSalesOrderReference(std::u8string reference) {
    salesOrderReference = OrderReferenceSalesOrderID{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setReceivingAdviceReference(std::u8string reference) {
    receivingAdviceReference = ReceiptDocumentReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setDespatchAdviceReference(std::u8string reference) {
    despatchAdviceReference = DespatchDocumentReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setTenderOrIotReference(std::u8string reference) {
    tenderOrIotReference = OriginatorDocumentReference{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setInvoicedObjectIdentifier(std::u8string id) {
    invoicedObjectIdentifier = AdditionalDocumentReferenceIdentifier{.type = {std::move(id)}};
}

void XRechnung::Invoice::setBuyerAccountingReference(std::u8string reference) {
    buyerAccountingReference = AccountingCost{.type = {std::move(reference)}};
}

void XRechnung::Invoice::setPaymentTerms(std::u8string terms) {
    paymentTerms = PaymentTerms{.type = {std::move(terms)}};
}

void XRechnung::Invoice::addInvoiceNote(std::u8string note, std::optional<std::u8string> subjectCode) {
    auto invoiceNote_ = INVOICE_NOTE();
    invoiceNote_.note = InvoiceNote{.type = {std::move(note)}};

    if (subjectCode)
        invoiceNote_.subjectCode = InvoiceNoteSubjectCode{.type = {std::move(subjectCode.value())}};

    invoiceNote.push_back(std::move(invoiceNote_));
}

void XRechnung::Invoice::setProcessControl(std::u8string processType, std::u8string specId) {
    processControl.processType = BusinessProcessType{.type = {std::move(processType)}};
    processControl.specificationIdentifier = SpecificationIdentifier{.type = {std::move(specId)}};
}

void XRechnung::Invoice::addPrecedingInvoiceReference(std::u8string reference, std::optional<std::u8string> issueDate) {
    auto vatInfo = VAT_INFORMATION();

    vatInfo.documentReference = InvoiceDocumentReference{.type = {std::move(reference)}};

    if (issueDate)
        vatInfo.issueDate = InvoiceDocumentReferenceIssueDate{.type = {std::move(issueDate.value())}};

    precedingInvoiceReference.push_back(std::move(vatInfo));
}

void XRechnung::Invoice::setSeller(const SellerProp &prop, const ElectronicAddress &electronicAddress, std::vector<std::u8string> identifier) {
    seller.name = SellerName{.type = {prop.name}};

    if (prop.tradingName)
        seller.tradingName = SellerTradingName{.type = {prop.tradingName.value()}};
    if (prop.legalIdentifier)
        seller.legalIdentifier = SellerLegalIdentifier{.type = {prop.legalIdentifier.value()}};
    if (prop.vatIdentifier)
        seller.vatIdentifier = SellerVATIdentifier{.type = {prop.vatIdentifier.value()}};
    if (prop.taxRegistrationIdentifier)
        seller.taxRegistrationIdentifier = SellerTaxRegistrationIdentifier{.type = {prop.taxRegistrationIdentifier.value()}};
    if (prop.additionalLegalInformation)
        seller.additionalLegalInformation = SellerAdditionalLegalInformation{.type = {prop.additionalLegalInformation.value()}};

    seller.electronicAddress = SellerElectronicAddress{.type = {electronicAddress.electronicAddress}};
    seller.electronicAddressSchema = SellerElectronicAddressSchema{.type = {getEASCode(electronicAddress.schema)}};

    seller.identifier.clear();
    for (const auto &element: identifier) {
        seller.identifier.emplace_back(SellerIdentifier{.type = {element}});
    }
}

void XRechnung::Invoice::setSellerAddress(const EntityAddress &address) {
    if (address.addressLine1)
        seller.address.address = SellerPostalAddressStreetName{.type = {address.addressLine1.value()}};
    if (address.addressLine2)
        seller.address.additional = SellerPostalAddressAdditionalStreetName{.type = {address.addressLine2.value()}};
    if (address.addressLine3)
        seller.address.additionalAddon = SellerPostalAddressAddressLine{.type = {address.addressLine3.value()}};

    seller.address.city = SellerPostalAddressCityName{.type = {address.city}};
    seller.address.postalCode = SellerPostalAddressPostalZone{.type = {address.postalCode}};

    if (address.countrySubentity)
        seller.address.countrySubentity = SellerPostalAddressCountrySubentity{.type = {address.countrySubentity.value()}};

    seller.address.countryCode = SellerPostalAddressCountryIdentificationCode{.type = {.id = address.countryCode, .content = address.countryCode}};
}

void XRechnung::Invoice::setSellerContact(std::u8string contact, std::u8string telephone, std::u8string eMail) {
    seller.contact.name = SellerContactName{.type = {std::move(contact)}};
    seller.contact.telephone = SellerContactTelephone{.type = {std::move(telephone)}};
    seller.contact.eMail = SellerContactEMail{.type = {std::move(eMail)}};
}

void XRechnung::Invoice::setBuyer(const BuyerProp &prop, const ElectronicAddress &electronicAddress) {
    if (prop.name)
        buyer.name = BuyerName{.type = {prop.name.value()}};
    if (prop.tradingName)
        buyer.tradingName = BuyerTradingName{.type = {prop.tradingName.value()}};
    if (prop.identifier)
        buyer.buyerId = BuyerIdentifier{.type = {prop.identifier.value()}};
    if (prop.legalRegistrationId)
        buyer.legalRegistrationId = BuyerLegalRegistrationIdentifier{.type = {prop.legalRegistrationId.value()}};
    if (prop.vatIdentifier)
        buyer.vatIdentifier = BuyerVATIdentifier{.type = {prop.vatIdentifier.value()}};

    buyer.electronicAddress = BuyerElectronicAddress{.type = {electronicAddress.electronicAddress}};
    buyer.electronicAddressSchema = BuyerElectronicAddressSchema{.type = {getEASCode(electronicAddress.schema)}};
}

void XRechnung::Invoice::setBuyerAddress(const EntityAddress &address) {
    if (address.addressLine1)
        buyer.address.address = BuyerAddressStreetName{.type = {address.addressLine1.value()}};
    if (address.addressLine2)
        buyer.address.additions = BuyerAddressAdditionalStreetName{.type = {address.addressLine2.value()}};
    if (address.addressLine3)
        buyer.address.additionsAddon = BuyerAddressAdditionalAddressLine{.type = {address.addressLine3.value()}};

    buyer.address.city = BuyerAddressCityName{.type = {address.city}};
    buyer.address.postalCode = BuyerAddressPostalZone{.type = {address.postalCode}};

    if (address.countrySubentity)
        buyer.address.countrySubdivision = BuyerAddressCountrySubentity{.type = {address.countrySubentity.value()}};

    buyer.address.countryCode = BuyerAddressCountryIdentificationCode{.type = {.id = address.countryCode, .content = address.countryCode}};
}

void XRechnung::Invoice::setBuyerContact(std::u8string contact, std::u8string telephone, std::u8string eMail) {
    auto buyerContact = BUYER_CONTACT();

    buyerContact.contactPoint = BuyerContact{.type = {std::move(contact)}};
    buyerContact.telephone = BuyerContactTelephone{.type = {std::move(telephone)}};
    buyerContact.email = BuyerContactEMail{.type = {std::move(eMail)}};

    buyer.contact = buyerContact;
}

void XRechnung::Invoice::setPayee(std::u8string name, std::optional<std::u8string> id, std::optional<std::u8string> legalRegistrationId) {
    auto payee_ = PAYEE();
    payee_.name = PayeeName{.type = {std::move(name)}};

    if (id)
        payee_.identifier = PayeeIdentifier{.type = {std::move(id.value())}};

    if (legalRegistrationId)
        payee_.legalRegistrationId = PayeeLegalRegistrationIdentifier{.type = {std::move(legalRegistrationId.value())}};

    payee = payee_;
}

void XRechnung::Invoice::setSellerTaxRepresentative(std::u8string name, std::u8string VatId, EntityAddress &address) {
    auto represent = SELLER_TAX_REPRESENTATIVE_PARTY();
    represent.representative = SellerTaxRepresentative{.type = {std::move(name)}};
    represent.vatIdentifier = SellerTaxRepresentativeVATIdentifier(std::move(VatId));

    if (address.addressLine1)
        represent.address.address = TaxRepresentativePostalAddressStreetName{.type = {std::move(address.addressLine1.value())}};
    if (address.addressLine2)
        represent.address.additional = TaxRepresentativePostalAddressAdditionalStreetName{.type = {std::move(address.addressLine2.value())}};
    if (address.addressLine3)
        represent.address.additionalAddon = TaxRepresentativePostalAddressAddressLine{.type = {std::move(address.addressLine3.value())}};

    represent.address.city = TaxRepresentativePostalAddressCity{.type = {std::move(address.city)}};
    represent.address.postalCode = TaxRepresentativePostalAddressPostCode{.type = {std::move(address.postalCode)}};

    if (address.countrySubentity)
        represent.address.addressSubentity = TaxRepresentativePostalAddressCountrySubentity{.type = {std::move(address.countrySubentity.value())}};

    represent.address.countryCode = TaxRepresentativePostalAddressCountryIdentificationCode{.type = {std::move(address.countryCode)}};

    sellerTaxRepresentative = represent;
}

void XRechnung::Invoice::setDeliveryInformation(std::optional<std::u8string> name, std::optional<std::u8string> locationId,
                                                std::optional<std::u8string> deliveryDate, std::optional<Period> invoicePeriod, std::optional<EntityAddress> address) {
    if (name || locationId || deliveryDate || invoicePeriod || address) {
        auto delivery = DELIVERY_INFORMATION();

        if (name)
            delivery.name = DeliveryName{.type = {std::move(name.value())}};
        if (locationId)
            delivery.identifier = DeliveryIdentifier{.type = {std::move(locationId.value())}};
        if (deliveryDate)
            delivery.deliveryDate = DeliveryDate{.type = {std::move(deliveryDate.value())}};

        if (invoicePeriod) {
            auto period = INVOICE_PERIOD();
            if (invoicePeriod.value().startDate)
                period.startDate = InvoicePeriodStartDate{.type = {std::move(invoicePeriod.value().startDate.value())}};
            if (invoicePeriod.value().endDate)
                period.endDate = InvoicePeriodEndDate{.type = {std::move(invoicePeriod.value().endDate.value())}};

            delivery.invoicePeriod = period;
        }

        // @TODO add address
        deliveryInformation = delivery;
    }
}

void XRechnung::Invoice::setPaymentInstructions(PaymentMeanCode typeCode, std::optional<std::u8string> txt, std::optional<std::u8string> remittanceInfo) {
    auto paymentMeansCode = stdStringToU8Str(std::to_string(static_cast<int>(std::move(typeCode))));
    paymentInstructions.code = XMapping::PaymentMeansCode{.type = XDataTypes::Code{.id = paymentMeansCode, .content = paymentMeansCode}};
    if (txt)
        paymentInstructions.text = PaymentMeansText{.type = {std::move(txt.value())}};

    if (remittanceInfo)
        paymentInstructions.paymentId = PaymentMeansPaymentId{.type = {std::move(remittanceInfo.value())}};
}

void XRechnung::Invoice::addCreditTransfer(std::u8string accountId, std::optional<std::u8string> accountName, std::optional<std::u8string> serviceProviderId) {
    auto creditTransfer = CREDIT_TRANSFER();
    creditTransfer.accountIdentifier = PayeeFinancialAccountIdentifier{.type = {std::move(accountId)}};
    if (accountName)
        creditTransfer.accountName = PayeeFinancialAccountName{.type = {std::move(accountName.value())}};
    if (serviceProviderId)
        creditTransfer.accountServiceProvide = PayeeFinancialAccountServiceProvider{.type = {std::move(serviceProviderId.value())}};

    paymentInstructions.creditTransfer.push_back(std::move(creditTransfer));
}

void XRechnung::Invoice::addPaymentCardInformation(std::u8string accountNumber, std::optional<std::u8string> cardHolder) {
    auto cardInfo = PAYMENT_CARD_INFORMATION();
    cardInfo.primaryNumber = PaymentCardAccountPrimaryNumber{.type = {std::move(accountNumber)}};
    if (cardHolder)
        cardInfo.holderName = PaymentCardAccountHolderName{.type = {std::move(cardHolder.value())}};

    paymentInstructions.cardInformation = cardInfo;
}

void XRechnung::Invoice::addPaymentDirectDebit(std::u8string mandateId, std::u8string bankId, std::u8string accountId) {
    auto directDebit = DIRECT_DEBIT();
    directDebit.mandateIdentifier = PaymentMandateIdentifier{.type = {std::move(mandateId)}};
    directDebit.assignedCreditorIdentifier = SellerBankAssignedCreditorIdentifier{.type = {std::move(bankId)}};
    directDebit.debitAccountIdentifier = PayeeBankAssignedCreditorIdentifier{.type = {std::move(accountId)}};

    paymentInstructions.directDebit = directDebit;
}

void XRechnung::Invoice::addAllowances(const VATChargeProp &prop) {
    auto doc = DOCUMENT_ALLOWANCES();
    doc.chargeIndicator = prop.chargeIndicator;
    doc.amount = AllowanceChargeAmount{.type = {prop.amount}, .currencyAttribute = {prop.currencyCode}};

    const auto reasonCode = stdStringToU8Str(std::to_string(static_cast<int>(prop.reasonCode)));
    doc.allowanceReasonCode = AllowanceChargeReasonCode{.type = {.id = reasonCode, .content = reasonCode}};

    if (prop.baseAmount)
        doc.baseAmount = AllowanceChargeBaseAmount{.type = {prop.baseAmount.value()}, .currencyAttribute = {prop.currencyCode}};
    if (prop.percentage)
        doc.percentage = AllowanceChargeMultiplier{.type = {prop.percentage.value()}};

    doc.taxCategoryCode = AllowanceChargeTaxCategory{.type = prop.VATCategoryCode};
    doc.vatRate = AllowanceChargeTaxCategoryPercentage{.type = {prop.VATPercentage}};

    if (prop.reason)
        doc.allowanceReason = AllowanceChargeReason{.type = {prop.reason.value()}};

    documentAllowances.push_back(std::move(doc));
}

void XRechnung::Invoice::addCharges(const VATChargeProp &prop) {
    auto doc = DOCUMENT_CHARGES();
    doc.chargeIndicator = prop.chargeIndicator;
    doc.amount = DocLevelAllowanceChargeAmount{.type = {prop.amount}, .currencyAttribute = {prop.currencyCode}};
    doc.reasonCode = DocLevelAllowanceChargeReasonCode{.type = {stdStringToU8Str(std::to_string(static_cast<int>(prop.reasonCode)))}};

    if (prop.baseAmount)
        doc.baseAmount = DocLevelAllowanceChargeBaseAmount{.type = {prop.baseAmount.value()}, .currencyAttribute = {prop.currencyCode}};
    if (prop.percentage)
        doc.percentage = DocLevelAllowanceChargePercentage{.type = {prop.percentage.value()}};

    doc.taxCategory = DocLevelAllowanceChargeTaxCategory{.type = prop.VATCategoryCode};
    doc.taxRate = DocLevelAllowanceChargeTaxRate({.type = {prop.VATPercentage}});

    if (prop.reason)
        doc.reason = DocLevelAllowanceChargeReason{.type = {prop.reason.value()}};

    documentCharges.push_back(std::move(doc));
}

void XRechnung::Invoice::setTotalInfo(const DocTotals &prop) {
    documentTotals.netAmount = LegalMonetaryTotalNetAmount{.type = {prop.sumInvoiceLineNetAmount}, .currencyAttribute = {prop.currencyCode}};

    if (prop.sumAllowances)
        documentTotals.totalAllowanceAmount = LegalMonetaryTotalAllowanceAmount{.type = {prop.sumAllowances.value()}, .currencyAttribute = {prop.currencyCode}};
    if (prop.sumCharges)
        documentTotals.totalCharges = LegalMonetaryTotalCharges{.type = {prop.sumCharges.value()}, .currencyAttribute = {prop.currencyCode}};

    documentTotals.amountWithoutTax = LegalMonetaryTotalTaxExclusiveAmount{.type = {prop.invoiceTotalAmountWithoutVAT}, .currencyAttribute = {prop.currencyCode}};

    if (prop.invoiceTotalTax)
        documentTotals.taxAmount = LegalMonetaryTotalVATAmount{.type = {prop.invoiceTotalTax.value()}, .currencyAttribute = {prop.currencyCode}};
    if (prop.invoiceTotalVATAmountInAccountingCurrency)
        documentTotals.taxAmountCurrency = LegalMonetaryTotalVATAmountCurrency{.type = {prop.invoiceTotalVATAmountInAccountingCurrency.value()},
                                                                               .currencyAttribute = {prop.currencyCode}};

    documentTotals.amountWithTax = LegalMonetaryTotalTaxInclusiveAmount{.type = {prop.invoiceTotalWithVAT}, .currencyAttribute = {prop.currencyCode}};

    if (prop.paidAmount)
        documentTotals.prepaidAmount = LegalMonetaryTotalPrepaidAmount{.type = {prop.paidAmount.value()}, .currencyAttribute = {prop.currencyCode}};
    if (prop.roundingAmount)
        documentTotals.roundingAmount = LegalMonetaryTotalPayableRoundingAmount{.type = {prop.roundingAmount.value()}, .currencyAttribute = {prop.currencyCode}};

    documentTotals.paymentAmountDue = LegalMonetaryTotalPayableAmount{.type = {prop.amountDueForPayment}, .currencyAttribute = {prop.currencyCode}};
}

void XRechnung::Invoice::addVATBreakdown(const VATProp &prop) {
    auto vat = VAT_BREAKDOWN();
    vat.taxableAmount = VATTaxableAmount{.type = {prop.taxableAmount}, .currencyAttribute = {prop.currencyCode}};
    vat.taxAmount = VATAmount{.type = {prop.taxAmount}, .currencyAttribute = {prop.currencyCode}};
    vat.categoryCode = VATCategoryCode{.type = prop.VATCategoryCode};
    vat.categoryRate = VATCategoryRate{.type = {prop.rate}};

    if (prop.reason)
        vat.reason = VATExemptionReason{.type = {prop.reason.value()}};
    if (prop.reasonCode)
        vat.reasonCode = VATExemptionReasonCode{.type = {prop.reasonCode.value()}};

    vatBreakdown.push_back(std::move(vat));
}

void XRechnung::Invoice::addAdditionalSupportingDocument(const AdditionalDoc &prop) {
    auto doc = ADDITIONAL_SUPPORTING_DOCUMENTS();
    doc.referenceIdentifier = SupportingDocumentReferenceIdentifier{.type = {prop.reference}};

    if (prop.description)
        doc.referenceDescription = AdditionalDocumentReferenceDescription{.type = {prop.description.value()}};
    if (prop.location)
        doc.externalReference = AdditionalDocumentExternalReference{.type = {prop.location.value()}};
    if (prop.document)
        doc.documentAttached = AdditionalDocumentAttached{.type = {prop.document.value()}};
}

XMapping::PRICE_DETAILS createPriceDetails(const XRechnung::PriceInfo &priceInfo) {
    auto obj = XMapping::PRICE_DETAILS();
    obj.netPrice = XMapping::ItemNetPrice{.type = {priceInfo.netPrice}, .currencyAttribute = {priceInfo.currencyCode}};
    if (priceInfo.discount)
        obj.discount = XMapping::ItemPriceDiscount{.type = {priceInfo.discount.value()}, .currencyAttribute = {priceInfo.currencyCode}};
    if (priceInfo.grossPrice)
        obj.grossPrice = XMapping::ItemGrossPrice{.type = {priceInfo.grossPrice.value()}, .currencyAttribute = {priceInfo.currencyCode}};
    if (priceInfo.quantity)
        obj.quantity = XMapping::ItemBaseQuantity{.type = {priceInfo.quantity.value()}};
    if (priceInfo.quantityMeasureUnit) {
        const auto measureUnitCode = getMeasurementCode(priceInfo.quantityMeasureUnit.value());
        obj.quantityCode = XMapping::ItemBaseQuantityCode{.type = {.id = measureUnitCode, .content = measureUnitCode}};
    }

    return obj;
}

XMapping::LINE_VAT_INFORMATION createVATInfo(const XRechnung::BaseVATProp &vatInfo) {
    auto obj = XMapping::LINE_VAT_INFORMATION();
    obj.categoryCode = XMapping::ItemVATCategoryCode{.type = vatInfo.VATCategoryCode};
    obj.percentage = XMapping::ItemVATRate{.type = {vatInfo.VATPercentage}};

    return obj;
}

XMapping::ITEM_INFORMATION createItemInformation(const XRechnung::ItemInfo &itemInfo) {
    auto obj = XMapping::ITEM_INFORMATION();
    obj.name = XMapping::ItemName{.type = {itemInfo.name}};
    if (itemInfo.description)
        obj.description = XMapping::ItemDescription{.type = {itemInfo.description.value()}};
    if (itemInfo.sellerId)
        obj.sellerIdentifier = XMapping::ItemSellerIdentifier{.type = {itemInfo.sellerId.value()}};
    if (itemInfo.buyerId)
        obj.buyerIdentifier = XMapping::ItemBuyerIdentifier{.type = {itemInfo.buyerId.value()}};
    if (itemInfo.standardId)
        obj.standardIdentifier = XMapping::ItemStandardIdentifier{.type = {itemInfo.standardId.value()}};
    if (itemInfo.countryOfOrigin)
        obj.itemOriginCountry = XMapping::ItemOriginCountryCode{.type = {itemInfo.countryOfOrigin.value()}};

    if (!itemInfo.classificationIds.empty())
        for (const auto &element: itemInfo.classificationIds) {
            obj.classificationIdentifier.emplace_back(XMapping::ItemClassificationIdentifier{.type = {element}});
        }

    if (!itemInfo.attributes.empty()) {
        for (const auto &itemAttr: itemInfo.attributes) {
            auto itemAttrObj = XMapping::ITEM_ATTRIBUTES();
            itemAttrObj.name = XMapping::ItemAttributeName{.type = {itemAttr.name}};
            itemAttrObj.value = XMapping::ItemAttributeValue{.type = {itemAttr.value}};
            obj.attributes.push_back(std::move(itemAttrObj));
        }
    }

    return obj;
}

SUB_ITEM_INFORMATION createSubItemInformation(const XRechnung::ItemInfo &itemInfo)
{
    auto sub_invoice_item = SUB_ITEM_INFORMATION{.name={itemInfo.name}};
    if (itemInfo.description)
        sub_invoice_item.description = ItemDescription{.type={*itemInfo.description}};
    if (itemInfo.sellerId)
        sub_invoice_item.sellerIdentifier = ItemSellerIdentifier{.type={*itemInfo.sellerId}};
    if (itemInfo.buyerId)
        sub_invoice_item.buyerIdentifier = ItemBuyerIdentifier{.type={*itemInfo.buyerId}};
    if (itemInfo.standardId)
        sub_invoice_item.standardIdentifier = ItemStandardIdentifier{.type={*itemInfo.standardId}};
    if (itemInfo.description)
        sub_invoice_item.description = ItemDescription{.type={*itemInfo.description}};
    if (itemInfo.description)
        sub_invoice_item.description = ItemDescription{.type={*itemInfo.description}};
    if (!itemInfo.classificationIds.empty())
        for (const auto &elem: itemInfo.classificationIds) {
            sub_invoice_item.classificationIdentifier.push_back({.type={elem}});
        }
    if (itemInfo.countryOfOrigin)
        sub_invoice_item.itemOriginCountry = ItemOriginCountryCode{.type={*itemInfo.countryOfOrigin}};
    if (!itemInfo.attributes.empty())
        for (const auto &elem: itemInfo.attributes) {
            sub_invoice_item.attributes.push_back({.name={elem.name}, .value={elem.value}});
        }
    return sub_invoice_item;
}


SUB_PRICE_DETAILS createSubPriceDetails(const XRechnung::PriceInfo &priceInfo, const XRechnungUtils::ISO4217_CurrencyCode currencyCode)
{
    const auto price_details_currency = priceInfo.currencyCode != ISO4217_CurrencyCode::Unknown ? priceInfo.currencyCode : currencyCode;
    auto sub_price_details = SUB_PRICE_DETAILS{.netPrice={.type={priceInfo.netPrice}, .currencyAttribute={price_details_currency}}};
    if (priceInfo.discount)
        sub_price_details.discount = ItemPriceDiscount{.type={*priceInfo.discount},
                                                       .currencyAttribute={.currencyCode=price_details_currency}};
    if (priceInfo.grossPrice)
        sub_price_details.grossPrice = ItemGrossPrice{.type={*priceInfo.grossPrice},
                                                      .currencyAttribute={.currencyCode=price_details_currency}};
    if (priceInfo.quantity)
        sub_price_details.quantity = ItemBaseQuantity{.type={*priceInfo.quantity}};
    if (priceInfo.quantityMeasureUnit)
    {
        const auto measureUnitCode = getMeasurementCode(*priceInfo.quantityMeasureUnit);
        sub_price_details.quantityCode = ItemBaseQuantityCode{.type={.id=measureUnitCode, .content=measureUnitCode}};
    }
    return sub_price_details;
}


void XRechnung::Invoice::addInvoiceLine(const InvoiceLine &line) {
    auto obj = INVOICE_LINE();

    obj.identifier = InvoiceLineIdentifier{.type = {line.id}};

    if (line.note)
        obj.note = InvoiceLineNote{.type = {line.note.value()}};
    if (line.objectId)
        obj.objectIdentifier = InvoiceLineObjectIdentifier{.type = {line.objectId.value()}};

    const auto measureUnitCode = getMeasurementCode(line.quantityMeasureUnit);
    obj.quantity = InvoiceLineQuantity{.type = {line.quantity}};
    obj.quantityUnit = InvoiceLineQuantityUnit{.type = {.id = measureUnitCode, .content = measureUnitCode}};
    obj.netAmount = InvoiceLineNetAmount{.type = {line.netAmount}, .currencyAttribute = {line.currencyCode}};

    if (line.orderReference)
        obj.orderReference = InvoiceLineOrderReference{.type = {line.orderReference.value()}};
    if (line.buyerAccountingReference)
        obj.buyerAccountingReference = InvoiceLineAccountingCost{.type = {line.buyerAccountingReference.value()}};
    if (line.period) {
        if (line.period.value().startDate)
            obj.period.startDate = InvoiceLinePeriodStartDate{.type = {line.period.value().startDate.value()}};
        if (line.period.value().endDate)
            obj.period.endDate = InvoiceLinePeriodEndDate{.type = {line.period.value().endDate.value()}};
    }

    obj.priceDetails = createPriceDetails(line.priceDetail);
    obj.vatInformation = createVATInfo(line.VATInfo);
    obj.itemInformation = createItemInformation(line.itemInfo);

    if (!line.allowances.empty())
        for (const auto &prop: line.allowances) {
            auto allow = INVOICE_LINE_ALLOWANCES();
            allow.chargeIndicator = prop.chargeIndicator;
            allow.amount = InvoiceLineAllowanceAmount{.type = {prop.amount}, .currencyAttribute = {line.currencyCode}};
            const auto reasonCode = stdStringToU8Str(std::to_string(static_cast<int>(prop.reasonCode)));
            allow.reasonCode = InvoiceLineAllowanceReasonCode{.type = XDataTypes::Code{.id = reasonCode, .content = reasonCode}};

            if (prop.baseAmount)
                allow.baseAmount = InvoiceLineAllowanceBaseAmount{.type = {prop.baseAmount.value()}, .currencyAttribute = {line.currencyCode}};
            if (prop.percentage)
                allow.percentage = InvoiceLineAllowancePercentage{.type = {prop.percentage.value()}};
            if (prop.reason)
                allow.reason = InvoiceLineAllowanceReason{.type = {prop.reason.value()}};
            obj.allowances.push_back(std::move(allow));
        }

    if (!line.charges.empty())
        for (const auto &prop: line.charges) {
            auto charge = INVOICE_LINE_CHARGES();
            charge.chargeIndicator = prop.chargeIndicator;
            charge.amount = InvoiceLineChargeAmount{.type = {prop.amount}, .currencyAttribute = {line.currencyCode}};
            const auto reasonCode = stdStringToU8Str(std::to_string(static_cast<int>(prop.reasonCode)));
            charge.reasonCode = InvoiceLineChargeReasonCode{.type = XDataTypes::Code{.id = reasonCode, .content = reasonCode}};

            if (prop.baseAmount)
                charge.baseAmount = InvoiceLineChargeBaseAmount{.type = {prop.baseAmount.value()}, .currencyAttribute = {line.currencyCode}};
            if (prop.percentage)
                charge.percentage = InvoiceLineChargePercentage{.type = {prop.percentage.value()}};
            if (prop.reason)
                charge.reason = InvoiceLineChargeReason{.type = {prop.reason.value()}};

            obj.charges.push_back(std::move(charge));
        }

    if (!line.sub_lines.empty())
        for (const auto &subLine : line.sub_lines)
        {
            auto subInvoiceLine = SUB_INVOICE_LINE{
                    .identifier = {.type = { subLine.id }},
                    .quantity = {.type = {subLine.quantity}},
                    .quantityUnit = { .type = {measureUnitCode, measureUnitCode}},
                    .netAmount = {.type = {.content = subLine.netAmount}, .currencyAttribute = {line.currencyCode}},
                    .itemInformation = createSubItemInformation(subLine.itemInfo),
                    .vatInformation = {.categoryCode={.type=subLine.VATInfo.VATCategoryCode},
                                       .percentage=ItemVATRate{.type={subLine.VATInfo.VATPercentage}}},
                    .priceDetails = createSubPriceDetails(subLine.priceDetail, line.currencyCode)
            };

            if (subLine.note)
                obj.note = InvoiceLineNote{.type={subLine.note.value()}};

            if (subLine.objectId)
                obj.objectIdentifier = InvoiceLineObjectIdentifier{.type={subLine.objectId.value()}};
            obj.subLines.push_back(subInvoiceLine);
        }

    invoiceLine.push_back(std::move(obj));
}

void XRechnung::setLineAllowanceAmount(INVOICE_LINE_ALLOWANCES &lineAllowance, const double amount, const ISO4217_CurrencyCode currencyCode) {
    lineAllowance.amount = InvoiceLineAllowanceAmount{.type = {.content = amount}, .currencyAttribute = {.currencyCode = currencyCode}};
}

void XRechnung::setLineAllowanceReason(INVOICE_LINE_ALLOWANCES &lineAllowance, const AllowanceChargeCode &reasonCode,
                                       const std::u8string &reasonTxt) {
    lineAllowance.reasonCode = InvoiceLineAllowanceReasonCode{.type = {.id = u8"", .content = stdStringToU8Str(std::to_string(static_cast<int>(reasonCode)))}};
    if (!reasonTxt.empty())
        lineAllowance.reason = InvoiceLineAllowanceReason{.type = {.content = reasonTxt}};
}

void XRechnung::setLineAllowanceBaseAmount(INVOICE_LINE_ALLOWANCES &lineAllowance, const double amount,
                                           const ISO4217_CurrencyCode currencyCode) {
    lineAllowance.baseAmount = InvoiceLineAllowanceBaseAmount{.type = {.content = amount},
                                                              .currencyAttribute = {.currencyCode = currencyCode}};
}

void XRechnung::setLineAllowancePercentage(INVOICE_LINE_ALLOWANCES &lineAllowance, const double percent) {
    lineAllowance.percentage = InvoiceLineAllowancePercentage{.type = {percent}};
}

void XRechnung::setLineChargeAmount(INVOICE_LINE_CHARGES &lineCharge, const double amount, const ISO4217_CurrencyCode currencyCode) {
    lineCharge.amount = InvoiceLineChargeAmount{.type = {.content = amount}, .currencyAttribute = {.currencyCode = currencyCode}};
}

void XRechnung::setLineChargeReason(INVOICE_LINE_CHARGES &lineCharge, const ChargeReasonCode &reasonCode, const std::u8string &reasonTxt) {
    lineCharge.reasonCode = InvoiceLineChargeReasonCode{.type = {.id = u8"", .content = getChargeReasonCode(reasonCode)}};
    if (!reasonTxt.empty())
        lineCharge.reason = InvoiceLineChargeReason{.type = {.content = reasonTxt}};
}

void XRechnung::setLineChargeBaseAmount(XMapping::INVOICE_LINE_CHARGES &lineCharge, const double amount,
                                        const XRechnungUtils::ISO4217_CurrencyCode currencyCode) {
    lineCharge.baseAmount = XMapping::InvoiceLineChargeBaseAmount{.type = {.content = amount},
                                                                  .currencyAttribute = {.currencyCode = currencyCode}};
}

void XRechnung::setLineChargePercentage(XMapping::INVOICE_LINE_CHARGES &lineCharge, const double percent) {
    lineCharge.percentage = XMapping::InvoiceLineChargePercentage{.type = {.content = percent}};
}
