#include <XRechnung/XRechnung.hpp>
#include <XRechnung/XRechnungCountryCode.hpp>
#include <XRechnung/XRechnungEASCode.hpp>
#include <XRechnung/XRechnungMeasureUnit.hpp>
#include <XRechnung/XRechnungPaymentMeansCode.hpp>
#include <XRechnung/XRechnungSerializer.hpp>
#include <XRechnung/XRechnungAllowanceChargeCode.hpp>

#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("SubInvoiceLineXml", "[XRechnung]")
{
    auto obj = XRechnung::Invoice();

    obj.setInvoiceNumber(u8"TOSL110");
    obj.setInvoiceTypeCode(XRechnungUtils::InvoiceType::Commercial);
    obj.setIssueDate(u8"2024-06-01");
    obj.setCurrencyCode(XRechnungUtils::ISO4217_CurrencyCode::Euro);
    obj.setDueDate(u8"2024-07-01");

    obj.setBuyerReference(u8"04011000-12345-03");

    obj.setSeller({ u8"SellerCompany", std::nullopt, u8"DE 123456789MVA" }, { u8"invoice@SellerCompany.com", XRechnungUtils::EASCode::Electronic_Mail });
    obj.setSellerContact(u8"SellerCompany", u8"05695325874", u8"info@SellerCompany.com");
    obj.setSellerAddress({ .city = u8"Town", .postalCode = u8"123456", .countryCode = XRechnungUtils::CountryCodes->at(u8"Deutschland").data() });

    obj.setBuyer({ u8"BuyerName", std::nullopt, u8"125856" }, { u8"buyer@google.com" , XRechnungUtils::EASCode::Electronic_Mail });
    obj.setBuyerAddress({ .addressLine1 = u8"Street", .city = u8"Town", .postalCode = u8"123456", .countryCode = XRechnungUtils::CountryCodes->at(u8"Deutschland").data() });

    obj.setPaymentInstructions(XRechnungUtils::PaymentMeanCode::SEPA_credit_transfer);
    obj.addCreditTransfer(u8"DE75512108001245126199");

    obj.setTotalInfo({
            .sumInvoiceLineNetAmount = 4000,
            .invoiceTotalAmountWithoutVAT = 4000,
            .invoiceTotalWithVAT = 4675,
            .amountDueForPayment = 4675,
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro
    });

    obj.addVATBreakdown({
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro,
            .taxableAmount = 1500,
            .taxAmount = 375,
            .VATCategoryCode = XRechnungUtils::VATCategory::StandardRate,
            .rate = 25
    });

    obj.addVATBreakdown({
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro,
            .taxableAmount = 2500,
            .taxAmount = 300,
            .VATCategoryCode = XRechnungUtils::VATCategory::StandardRate,
            .rate = 12
    });

    obj.addInvoiceLine({
            .id = u8"1",
            .quantity = 1000,
            .quantityMeasureUnit = XRechnungUtils::MEASURE_UNIT::Each,
            .netAmount = 1000,
            .priceDetail = { .netPrice=1, .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro },
            .VATInfo = { .VATCategoryCode = XRechnungUtils::VATCategory::StandardRate, .VATPercentage = 25},
            .itemInfo = { .name = u8"Screw 8x8" },
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro
    });

    obj.addInvoiceLine({
            .id = u8"2",
            .quantity = 100,
            .quantityMeasureUnit = XRechnungUtils::MEASURE_UNIT::Each,
            .netAmount = 500,
            .priceDetail = {.netPrice = 5, .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro },
            .VATInfo = {.VATCategoryCode = XRechnungUtils::VATCategory::StandardRate, .VATPercentage = 25},
            .itemInfo = {.name = u8"Screw 16x8" },
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro
    });

    obj.addInvoiceLine({
            .id = u8"3",
            .quantity = 500,
            .quantityMeasureUnit = XRechnungUtils::MEASURE_UNIT::Each,
            .netAmount = 2500,
            .priceDetail = {.netPrice = 5, .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro },
            .VATInfo = {.VATCategoryCode = XRechnungUtils::VATCategory::StandardRate, .VATPercentage = 12},
            .itemInfo = {.name = u8"Cookies" },
            .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro,
            .sub_lines = {
                {
                        .id = u8"1",
                        .quantity = 500,
                        .quantityMeasureUnit = XRechnungUtils::MEASURE_UNIT::Each,
                        .netAmount = 500,
                        .priceDetail = {.netPrice = 1, .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro },
                        .VATInfo = {.VATCategoryCode = XRechnungUtils::VATCategory::StandardRate, .VATPercentage = 12},
                        .itemInfo = {.name = u8"CholcateChips" },
                    },
                {
                        .id = u8"2",
                        .quantity = 500,
                        .quantityMeasureUnit = XRechnungUtils::MEASURE_UNIT::Each,
                        .netAmount = 1000,
                        .priceDetail = {.netPrice = 2, .currencyCode = XRechnungUtils::ISO4217_CurrencyCode::Euro },
                        .VATInfo = {.VATCategoryCode = XRechnungUtils::VATCategory::StandardRate, .VATPercentage = 12},
                        .itemInfo = {.name = u8"Butter" },
                    }
            }
    });

    const auto xmlResult = XRechnung::Serializer::XmlWriter().serialize(obj);

    REQUIRE_FALSE(xmlResult.empty());
    write_to_file(xmlResult, "sub_invoice");
}