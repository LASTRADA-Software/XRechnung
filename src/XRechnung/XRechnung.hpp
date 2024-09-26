#pragma once
#include <XRechnung/XRechnungProp.hpp>
#include <XRechnung/XRechnungAllowanceChargeCode.hpp>

#include <cstdint>
#include <optional>
#include <vector>


namespace XRechnungUtils {
    enum class ChargeReasonCode : uint16_t;
    enum class PaymentMeanCode : uint16_t;
}// namespace XRechnungUtils

namespace XRechnung {
    using namespace XMapping;

    /**
   * The root element for an `XRechnung`
   */
    class Invoice {
    private:
        InvoiceNumber invoiceNumber{};
        InvoiceIssueDate invoiceIssueDate{};
        InvoiceTypeCode invoiceTypeCode{};
        DocumentCurrencyCode invoiceCurrencyCode{};
        TaxCurrencyCode accountingCurrencyCode{};
        std::optional<TaxPointDate> taxPointDate{std::nullopt};
        DueDate dueDate{};
        BuyerReference buyerReference{};
        std::optional<ProjectReference> projectReference{std::nullopt};
        std::optional<ContractDocumentReference> contractReference{std::nullopt};
        std::optional<OrderReference> orderReference{std::nullopt};
        std::optional<OrderReferenceSalesOrderID> salesOrderReference{std::nullopt};
        std::optional<ReceiptDocumentReference> receivingAdviceReference{std::nullopt};
        std::optional<DespatchDocumentReference> despatchAdviceReference{std::nullopt};
        std::optional<OriginatorDocumentReference> tenderOrIotReference{std::nullopt};
        std::optional<AdditionalDocumentReferenceIdentifier> invoicedObjectIdentifier{std::nullopt};
        //std::optional<AdditionalDocumentReferenceSchemaId> invoicedObjectIdentifierSchema{ std::nullopt };
        std::optional<AccountingCost> buyerAccountingReference{std::nullopt};
        std::optional<PaymentTerms> paymentTerms{std::nullopt};
        std::vector<INVOICE_NOTE> invoiceNote{};
        PROCESS_CONTROL processControl{};
        std::vector<VAT_INFORMATION> precedingInvoiceReference{};
        SELLER seller{};
        BUYER buyer{};
        std::optional<PAYEE> payee{std::nullopt};
        std::optional<SELLER_TAX_REPRESENTATIVE_PARTY> sellerTaxRepresentative{std::nullopt};
        std::optional<DELIVERY_INFORMATION> deliveryInformation{std::nullopt};
        PAYMENT_INSTRUCTIONS paymentInstructions{};
        std::vector<DOCUMENT_ALLOWANCES> documentAllowances{};
        std::vector<DOCUMENT_CHARGES> documentCharges{};
        DOCUMENT_TOTALS documentTotals{};
        std::vector<VAT_BREAKDOWN> vatBreakdown{};
        std::vector<ADDITIONAL_SUPPORTING_DOCUMENTS> additionalSupportingDocuments{};
        std::vector<INVOICE_LINE> invoiceLine{};

        struct InvoiceXMLAttribute {
            std::u8string_view key{};
            std::u8string value{};
        };

        std::vector<InvoiceXMLAttribute> xmlAttributes{
                {u8"xmlns:ubl", u8"urn:oasis:names:specification:ubl:schema:xsd:Invoice-2"},
                {u8"xmlns:cac", u8"urn:oasis:names:specification:ubl:schema:xsd:CommonAggregateComponents-2"},
                {u8"xmlns:cbc", u8"urn:oasis:names:specification:ubl:schema:xsd:CommonBasicComponents-2"}};

    public:
        [[nodiscard]] InvoiceNumber getInvoiceNumber() const { return invoiceNumber; }
        [[nodiscard]] InvoiceIssueDate getInvoiceIssueDate() const { return invoiceIssueDate; }
        [[nodiscard]] InvoiceTypeCode getInvoiceTypeCode() const { return invoiceTypeCode; }
        [[nodiscard]] DocumentCurrencyCode getInvoiceCurrencyCode() const { return invoiceCurrencyCode; }
        [[nodiscard]] TaxCurrencyCode getAccountingCurrencyCode() const { return accountingCurrencyCode; }
        [[nodiscard]] std::optional<TaxPointDate> getTaxPointDate() const { return taxPointDate; }
        [[nodiscard]] DueDate getDueDate() const { return dueDate; }
        [[nodiscard]] BuyerReference getBuyerReference() const { return buyerReference; }
        [[nodiscard]] std::optional<ProjectReference> getProjectReference() const { return projectReference; }
        [[nodiscard]] std::optional<ContractDocumentReference> getContractReference() const { return contractReference; }
        [[nodiscard]] std::optional<OrderReference> getOrderReference() const { return orderReference; }
        [[nodiscard]] std::optional<OrderReferenceSalesOrderID> getSalesOrderReference() const { return salesOrderReference; }
        [[nodiscard]] std::optional<ReceiptDocumentReference> getReceivingAdviceReference() const { return receivingAdviceReference; }
        [[nodiscard]] std::optional<DespatchDocumentReference> getDespatchAdviceReference() const { return despatchAdviceReference; }
        [[nodiscard]] std::optional<OriginatorDocumentReference> getTenderOrIotReference() const { return tenderOrIotReference; }
        [[nodiscard]] std::optional<AdditionalDocumentReferenceIdentifier> getInvoicedObjectIdentifier() const { return invoicedObjectIdentifier; }
        //std::optional<AdditionalDocumentReferenceSchemaId> getInvoicedObjectIdentifierSchema() const { return invoicedObjectIdentifierSchema; }
        [[nodiscard]] std::optional<AccountingCost> getBuyerAccountingReference() const { return buyerAccountingReference; }
        [[nodiscard]] std::optional<PaymentTerms> getPaymentTerms() const { return paymentTerms; }
        [[nodiscard]] std::vector<INVOICE_NOTE> getInvoiceNote() const { return invoiceNote; }
        [[nodiscard]] PROCESS_CONTROL getProcessControl() const { return processControl; }
        [[nodiscard]] std::vector<VAT_INFORMATION> getPrecedingInvoiceReference() const { return precedingInvoiceReference; }
        [[nodiscard]] SELLER getSeller() const { return seller; }
        [[nodiscard]] BUYER getBuyer() const { return buyer; }
        [[nodiscard]] std::optional<PAYEE> getPayee() const { return payee; }
        [[nodiscard]] std::optional<SELLER_TAX_REPRESENTATIVE_PARTY> getSellerTaxRepresentative() const { return sellerTaxRepresentative; }
        [[nodiscard]] std::optional<DELIVERY_INFORMATION> getDeliveryInformation() const { return deliveryInformation; }
        [[nodiscard]] PAYMENT_INSTRUCTIONS getPaymentInstructions() const { return paymentInstructions; }
        [[nodiscard]] std::vector<DOCUMENT_ALLOWANCES> getDocumentAllowances() const { return documentAllowances; }
        [[nodiscard]] std::vector<DOCUMENT_CHARGES> getDocumentCharges() const { return documentCharges; }
        [[nodiscard]] DOCUMENT_TOTALS getDocumentTotals() const { return documentTotals; }
        [[nodiscard]] std::vector<VAT_BREAKDOWN> getVatBreakdown() const { return vatBreakdown; }
        [[nodiscard]] std::vector<ADDITIONAL_SUPPORTING_DOCUMENTS> getAdditionalSupportingDocuments() const { return additionalSupportingDocuments; }
        [[nodiscard]] std::vector<INVOICE_LINE> getInvoiceLine() const { return invoiceLine; }
        [[nodiscard]] std::vector<INVOICE_LINE> *getInvoiceLineRef() { return &invoiceLine; }
        INVOICE_LINE *getInvoiceLineRef(const int idx) { return &invoiceLine[idx]; }
        [[nodiscard]] std::vector<InvoiceXMLAttribute> getXMLAttributes() const { return xmlAttributes; }

        /**
     * Eine eindeutige Kennung der Rechnung, die diese im System des Verkäufers identifiziert.
     * @param number
     */
        void setInvoiceNumber(std::u8string number) noexcept;

        /**
     * Das Datum, an dem die Rechnung ausgestellt wurde
     * @param dateStr 
     */
        void setIssueDate(std::u8string dateStr) noexcept;

        /**
     * Ein Code, der den Funktionstyp der Rechnung angibt.
     * @param type 
     */
        void setInvoiceTypeCode(InvoiceType type) noexcept;

        /**
     * Die Waehrung, in der alle Rechnungsbeträge angegeben werden, ausgenommen ist der Umsatzsteuer-Gesamtbetrag, der in der Abrechnungswährung anzugeben ist.
     * @param currencyCode ISO 4217 conform.
     */
        void setCurrencyCode(ISO4217_CurrencyCode currencyCode);

        /**
     * Die für die Umsatzsteuer-Abrechnungs- und -Meldezwecke verwendete Währung, die im Land des Verkäufers gültig ist oder verlangt wird.
     * @param currencyCode ISO 4217 conform.
     */
        void setAccountingCurrencyCode(ISO4217_CurrencyCode currencyCode);

        /**
     * Das Datum, zu dem die Umsatzsteuer für den Verkäufer und für den Erwerber abrechnungsrelevant wird.
     * @param dateStr 
     */
        void setTaxPointDate(std::u8string dateStr);

        /**
     * Ein Code für den Zeitpunkt, an dem die Umsatzsteuer für den Erwerber und den Verkäufer in der Buchführung nachzuweisen ist.
     * @param dateCode 
     */
        void setPeriodDescriptionCode(PointDateCode dateCode);

        /**
     * Das Fälligkeitsdatum des Rechnungsbetrages.
     * @param dateStr 
     */
        void setDueDate(std::u8string dateStr);

        /**
     * Ein vom Erwerber zugewiesener und für interne Lenkungszwecke benutzter Bezeichner.
     * @param reference
     */
        void setBuyerReference(std::u8string reference);

        /**
     * [Optional]
     * Die Kennung eines Projektes, auf das sich die Rechnung bezieht.
     * @param reference 
     */
        void setProjectReference(std::u8string reference);

        /**
     * [Optional]
     * Eine eindeutige Bezeichnung des Vertrages (z. B. Vertragsnummer).
     * @param reference 
     */
        void setContractReference(std::u8string reference);

        /**
     * [Optional]
     * Eine vom Erwerber ausgegebene Kennung für eine referenzierte Bestellung.
     * @param reference 
     */
        void setOrderReference(std::u8string reference);

        /**
     * [Optional]
     * Eine vom Verkäufer ausgegebene Kennung für einen referenzierten Auftrag.
     * @param reference 
     */
        void setSalesOrderReference(std::u8string reference);

        /**
     * [Optional]
     * Eine Kennung für eine referenzierte ä
     * @param reference 
     */
        void setReceivingAdviceReference(std::u8string reference);

        /**
     * [Optional]
     * Eine Kennung für eine referenzierte Versandanzeige.
     * @param reference 
     */
        void setDespatchAdviceReference(std::u8string reference);

        /**
     * [Optional]
     * Die Kennung der Ausschreibung oder des Loses auf die/das sich die Rechnung bezieht.
     * @param reference 
     */
        void setTenderOrIotReference(std::u8string reference);

        /**
     * [Optional]
     * Eine vom Verkäufer angegebene Kennung für ein Objekt, auf das sich die Rechnung bezieht (z. B. Zählernummer, Telefonnummer, Kfz-Kennzeichen, versicherte Person, Abonnement-Nummer, Rufnummer).
     * @param id 
     */
        void setInvoicedObjectIdentifier(std::u8string id);

        /**
     * [Optional]
     * Ein Textwert, der angibt, an welcher Stelle die betreffenden Daten in den Finanzkonten des Erwerbers zu buchen sind.
     * @param reference 
     */
        void setBuyerAccountingReference(std::u8string reference);

        /**
     * [Optional]
     * Eine Textbeschreibung der Zahlungsbedingungen, die für den fälligen Zahlungsbetrag gelten (einschließlich
Beschreibung möglicher Skontobedingungen). Dieses Informationselement kann mehrere Zeilen und mehrere
Angaben zu Zahlungsbedingungen beinhalten und sowohl unstrukturierten als strukturierten Text enthalten
    Jeder Eintrag beginnt mit einer #, die Segmente sind mit einer # getrennt und eine Zeile schließt mit einer # ab.

Am Ende einer vollständigen Skontoangabe muss ein XML-konformer Zeilenumbruch folgen.

Beispiele mit drei Segmenten je Zeile:
#SKONTO#TAGE=14#PROZENT=2.25#

#SKONTO#TAGE=28#PROZENT=1.00#

Beispiele mit vier Segmenten je Zeile (die Gewährung von Skonto bezieht sich nur auf einen Teilbetrag der Rechnung (z. B. Material) und der Grundwert zur Berechnung des Skonto muss mit angegeben werden):

#SKONTO#TAGE=14#PROZENT=2.25#BASISBETRAG=357.93#

#SKONTO#TAGE=28#PROZENT=1.00#BASISBETRAG=357.93#
     * @param terms 
     */
        void setPaymentTerms(std::u8string terms);

        /**
     * 
     * @param note Ein Textvermerk, der unstrukturierte Informationen enthält, die für die Rechnung als Ganzes maßgeblich sind.
Erforderlichenfalls können Angaben zur Aufbewahrungspflicht gem. § 14 Abs. 4 Nr. 9 UStG hier aufgenommen werden.

Anmerkung: Im Falle einer bereits fakturierten Rechnung kann hier z. B. der Grund der Korrektur angegeben werden
     *
     * @param subjectCode Der Betreff für den nachfolgenden Textvermerk zur Rechnung.
     */
        void addInvoiceNote(std::u8string note, std::optional<std::u8string> subjectCode = std::nullopt);

        /**
     * 
     * @param processType Identifiziert den Kontext des Geschäftsprozesses, in dem die Transaktion erfolgt.
    Er erm�glicht es dem Erwerber, die Rechnung in angemessener Weise zu verarbeiten.
     *
     * @param specId Eine Kennung der Spezifikation, die das gesamte Regelwerk zum semantischen Inhalt, zu den Kardinalitäten und
den Geschäftsregeln enthält, dem die in der Rechnung enthaltenen Daten entsprechen.
     */
        void setProcessControl(std::u8string processType, std::u8string specId);

        /**
     * [Optional]
     * @param reference Die Kennung der vorausgegangenen Rechnung, auf die Bezug genommen wird.
     * @param issueDate Das Datum, zu dem die vorausgegangene Rechnung ausgestellt wurde.
     */
        void addPrecedingInvoiceReference(std::u8string reference, std::optional<std::u8string> issueDate);

        /**
     * 
     * @param prop.trading Name Ein Name, unter dem der Verkäufer bekannt ist, sofern abweichend vom Namen des Verkäufers.
     * @param prop.legalIdentifier Eine von einer offiziellen Registrierstelle ausgegebene Kennung, die den Verkäufer als Rechtsträger oder juristische Person identifiziert.
     * @param prop.vatIdentifier Die Umsatzsteuer-Identifikationsnummer des Verkäufers. Verfügt der Verkäufer über eine solche, ist sie hier
anzugeben, sofern nicht Angaben zum "SELLER TAX REPRESENTATIVE PARTY" (BG-11) gemacht werden.
     * @param prop.taxRegistrationIdentifier Eine örtliche steuerrechtliche Kennung des Verkäufers (bestimmt durch dessen Adresse) oder ein Verweis auf
seinen eingetragenen Steuerstatus. (Hier ist ggf. die Angabe "Steuerschuldnerschaft des Leistungsempfängers"
oder die USt-Befreiung des Rechnungsstellers einzutragen.)
     * @param prop.additionalLegalInformation Weitere rechtliche Informationen, die für den Verkäufer maßgeblich sind (wie z. B. Grundkapital).
     * @param electronicAddress Gibt die elektronische Adresse des Verkäufers an, an die die Antwort der Anwendungsebene auf eine Rechnung gesendet werden kann.
     * @param identifier Eine (i. d. R. vom Erwerber vergebene) Kennung des Verkäufers, wie z. B. die Kreditorennummer für das Mittelbewirtschaftungsverfahren oder die Lieferantennummer für das Bestellsystem.
     */
        void setSeller(const SellerProp &prop, const ElectronicAddress &electronicAddress, std::vector<std::u8string> identifier = {});

        /**
     * 
     * @param address.addressLine1  Die Hauptzeile in einer Anschrift. üblicherweise ist dies entweder Strasse und Hausnummer oder der Text "Postfach" gefolgt von der Postfachnummer
     * @param address.addressLine2  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.addressLine3  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.city  Die Bezeichnung der Stadt oder Gemeinde, in der sich die Verkäuferanschrift befindet.
     * @param address.postalCode  Postleitzahl
     * @param address.countrySubentity  Die Unterteilung eines Landes (wie Region, Bundesland, Provinz etc.).
     * @param address.countryCode  Ein Code, mit dem das Land bezeichnet wird, nach ISO 3166-1. Nur Alpha 2 Darstellung ist erlaubt.
     */
        void setSellerAddress(const EntityAddress &address);

        /**
     * 
     * @param contact Angaben zu Ansprechpartner oder Kontaktstelle (wie z. B. Name einer Person, Abteilungs- oder Bürobezeichnung).
     * @param telephone Telefonnummer des Ansprechpartners oder der Kontaktstelle
     * @param eMail Eine E-Mail-Adresse des Ansprechpartners oder der Kontaktstelle.
     */
        void setSellerContact(std::u8string contact, std::u8string telephone, std::u8string eMail);

        /**
     * 
     * @param prop.name Der vollständig Name des Erwerbers.
     * @param prop.tradingName Ein Name, unter dem der Erwerber bekannt ist, sofern abweichend vom Namen des Erwerbers.
     * @param prop.identifier Eine (i. d. R. vom Verkäufer vergebene) Kennung des Erwerbers, wie z. B. die Debitorennummer für die Buchhaltung oder die Kundennnummer für die Auftragsverwaltung.
     * @param prop.legalRegistrationId Ein von einer offiziellen Registrierstelle ausgegebener Bezeichner, der den Erwerber als Rechtsträger oder juristische Person identifiziert. Z. B. Handelsregister-Eintrag, Vereinsregister etc.
     * @param prop.vatIdentifier Die Umsatzsteuer-Identifikationsnummer des Erwerbers.
     * @param electronicAddress Gibt eine elektronische Adresse des Erwerbers an, an die eine Rechnung gesendet werden sollte.
     */
        void setBuyer(const BuyerProp &prop, const ElectronicAddress &electronicAddress);

        /**
     *
     * @param address.addressLine1  Die Hauptzeile in einer Anschrift. üblicherweise ist dies entweder Strasse und Hausnummer oder der Text "Postfach" gefolgt von der Postfachnummer
     * @param address.addressLine2  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.addressLine3  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.city  Die Bezeichnung der Stadt oder Gemeinde, in der sich die Verkäuferanschrift befindet.
     * @param address.postalCode  Postleitzahl
     * @param address.countrySubentity  Die Unterteilung eines Landes (wie Region, Bundesland, Provinz etc.).
     * @param address.countryCode  Ein Code, mit dem das Land bezeichnet wird, nach ISO 3166-1. Nur Alpha 2 Darstellung ist erlaubt.
     */
        void setBuyerAddress(const EntityAddress &address);

        /**
     *
     * @param contact Angaben zu Ansprechpartner oder Kontaktstelle (wie z. B. Name einer Person, Abteilungs- oder Bürobezeichnung).
     * @param telephone Telefonnummer des Ansprechpartners oder der Kontaktstelle
     * @param eMail Eine E-Mail-Adresse des Ansprechpartners oder der Kontaktstelle.
     */
        void setBuyerContact(std::u8string contact, std::u8string telephone, std::u8string eMail);

        /**
     * [Optional]
     * @param name Der Name des Zahlungsempfängers.
     * @param id Eine Kennung für den Zahlungsempfänger.
     * @param legalRegistrationId Eine von einer offiziellen Registrierstelle ausgegebene Kennung, die den Zahlungsempfänger als einen Rechtsträger oder eine juristische Person identifiziert.
     */
        void setPayee(std::u8string name, std::optional<std::u8string> id, std::optional<std::u8string> legalRegistrationId);

        /**
     * [Optional]
     * @param name Der vollständig Name des Steuervertreters des Verkäufers.
     * @param VatId Die Umsatzsteuer-Identifikationsnummer des Steuervertreters des Verkäufers.
     * @param address.addressLine1  Die Hauptzeile in einer Anschrift. üblicherweise ist dies entweder Strasse und Hausnummer oder der Text  gefolgt von der Postfachnummer
     * @param address.addressLine2  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.addressLine3  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.city  Die Bezeichnung der Stadt oder Gemeinde, in der sich die Verkäuferanschrift befindet.
     * @param address.postalCode  Postleitzahl
     * @param address.countrySubentity  Die Unterteilung eines Landes (wie Region, Bundesland, Provinz etc.).
     * @param address.countryCode  Ein Code, mit dem das Land bezeichnet wird, nach ISO 3166-1. Nur Alpha 2 Darstellung ist erlaubt.
     */
        void setSellerTaxRepresentative(std::u8string name, std::u8string VatId, EntityAddress &address);

        /**
     * [Optional]
     * @param name Der Name des Empfängers, an den die Waren geliefert bzw. für den die Dienstleistungen erbracht werden.
     * @param locationId Ein Bezeichner für den Ort, an den die Waren geliefert oder an dem die Dienstleistungen erbracht werden.
     * @param deliveryDate Datum, an dem die Lieferung tatsächlich erfolgt bzw. die Dienstleistung tatsächlich erbracht wird.
     * @param invoicePeriod 
     * @param address.addressLine1  Die Hauptzeile in einer Anschrift. üblicherweise ist dies entweder Strasse und Hausnummer oder der Text "Postfach" gefolgt von der Postfachnummer
     * @param address.addressLine2  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.addressLine3  Eine zusätzliche Adresszeile in einer Anschrift, die verwendet werden kann, um weitere Einzelheiten in Ergänzung zur Hauptzeile anzugeben
     * @param address.city  Die Bezeichnung der Stadt oder Gemeinde, in der sich die Verkäuferanschrift befindet.
     * @param address.postalCode  Postleitzahl
     * @param address.countrySubentity  Die Unterteilung eines Landes (wie Region, Bundesland, Provinz etc.).
     * @param address.countryCode  Ein Code, mit dem das Land bezeichnet wird, nach ISO 3166-1. Nur Alpha 2 Darstellung ist erlaubt.
     */
        void setDeliveryInformation(std::optional<std::u8string> name, std::optional<std::u8string> locationId, std::optional<std::u8string> deliveryDate, std::optional<Period> invoicePeriod, std::optional<EntityAddress> address);

        /**
     * 
     * @param typeCode Das als Code ausgedrückte erwartete oder genutzte Zahlungsmittel. Hierzu wird auf die Codeliste UNTDID 4461 verwiesen.
     * @param txt Das in Textform ausgedrückte erwartete oder genutzte Zahlungsmittel.
     * @param remittanceInfo Ein Textwert, der zur Verknüpfung der Zahlung mit der vom Verkäufer ausgestellten Rechnung verwendet wird.
     */
        void setPaymentInstructions(PaymentMeanCode typeCode, std::optional<std::u8string> txt = std::nullopt, std::optional<std::u8string> remittanceInfo = std::nullopt);

        /**
     * [Optional]
     * @param accountId Die Kennung des Kontos, auf das die Zahlung erfolgen soll: IBAN für Zahlungen im SEPA-Raum, Kontonummer oder IBAN im Falle von Auslandszahlungen.
     * @param accountName Name des Kontos bei einem Zahlungsdienstleister, auf das die Zahlung erfolgen soll. (z. B. Kontoinhaber)
     * @param serviceProviderId Die Kennung des Konto führenden Zahlungsdienstleisters. Diese Kennung ergibt sich bei Zahlungen im SEPARaum im Regelfall aus der IBAN.
für alle Auslandszahlungen,
� außerhalb des SEPA-Raumes wird der Bank Identifier Code (BIC) benötigt. Dies wird durch Code 30 (Credit
transfer (non-SEPA) in `setPaymentInstructions`, `typeCode` (BT-81) gekennzeichnet.
� innerhalb des SEPA-Raumes wird der Bank Identifier Code (BIC) nicht benötigt. Es reicht die Angabe der
IBAN. Dies wird durch Code 58 "SCT" in `setPaymentInstructions`, `typeCode` (BT-81) gekennzeichnet. Ausgenommen
sind Zahlungen an Bankverbindungen z. B. in San Marino, Monaco, Schweiz, Saint Pierre und Miquelon: Hier
ist die Angabe des BIC zwingend erforderlich.
     */
        void addCreditTransfer(std::u8string accountId, std::optional<std::u8string> accountName = std::nullopt, std::optional<std::u8string> serviceProviderId = std::nullopt);

        /**
     * [Optional]
     * @param accountNumber Die Nummer der Kreditkarte, die für die Zahlung genutzt wurde.
     * @param cardHolder Name des Karteninhabers.
     */
        void addPaymentCardInformation(std::u8string accountNumber, std::optional<std::u8string> cardHolder);

        /**
     * [Optional]
     * @param mandateId Eindeutige Kennung, die vom Zahlungsempfänger zur Referenzierung der Einzugsermächtigung zugewiesen wird (Mandatsreferenznummer).
     * @param bankId Die eindeutige Kennung des Verkäufers (Seller) oder des Zahlungsempfängers (Payee), um am SEPA-Lastschriftverfahren teilnehmen zu können (Gläubiger-ID).
     * @param accountId Die Kennung des Kontos, von dem die Lastschrift erfolgen soll: IBAN für Zahlungen im SEPA-Raum, Kontonummer oder IBAN im Falle von Auslandszahlungen.
     */
        void addPaymentDirectDebit(std::u8string mandateId, std::u8string bankId, std::u8string accountId);

        /**
     * [Optional]
     * @param prop.amount Der Nachlassbetrag ohne Umsatzsteuer.
     * @param prop.reasonCode 
     * @param prop.baseAmount Der Grundbetrag, der in Verbindung mit der `percentage` (BT-94) zur Berechnung des `amount` (BT-92) verwendet werden kann.
     * @param prop.percentage 
     * @param prop.VATCategoryCode Ein Code für das Umsatzsteuermerkmal, das auf den `amount` (BT-92) anzuwenden ist
     * @param prop.VATPercentage Der für den `amount` (BT-92) geltende und in Prozent angegebene Umsatzsteuersatz.
     * @param prop.reason Der in Textform angegebene Grund für den `amount` (BT-92).
     * @param prop.reasonCode Der als Code angegebene Grund für den `amount` (BT-92).
     */
        void addAllowances(const VATAllowanceProp &prop);

        /**
   * [Optional]
   * @param prop.chargeIndicator boolean
   * @param prop.amount Der Nachlassbetrag ohne Umsatzsteuer.
   * @param prop.baseAmount Der Grundbetrag, der in Verbindung mit der `percentage` (BT-94) zur Berechnung des `amount` (BT-92) verwendet werden kann.
   * @param prop.percentage
   * @param prop.VATCategoryCode Ein Code für das Umsatzsteuermerkmal, das auf den `amount` (BT-92) anzuwenden ist
   * @param prop.VATPercentage Der für den `amount` (BT-92) geltende und in Prozent angegebene Umsatzsteuersatz.
   * @param prop.reason Der in Textform angegebene Grund für den `amount` (BT-92).
   * @param prop.reasonCode Der als Code angegebene Grund für den `amount` (BT-92).
   */
        void addCharges(const VATChargeProp &prop);

        /**
     * 
     * @param prop.sumInvoiceLineNetAmount 
     * @param prop.sumAllowances 
     * @param prop.sumCharges 
     * @param prop.invoiceTotalAmountWithoutVAT Der Gesamtbetrag der Rechnung ohne Umsatzsteuer.
     * @param prop.invoiceTotalVATAmount Der Gesamtbetrag der Umsatzsteuer für die Rechnung
     * @param prop.invoiceTotalVATAmountInAccountingCurrency Der Umsatzsteuergesamtbetrag, angegeben in der Abrechnungswährung, die im Land des Verkäufers gültig ist oder verlangt wird.
     * @param prop.invoiceTotalWithVAT Der Gesamtbetrag der Rechnung mit Umsatzsteuer.
     * @param prop.paidAmount Summe bereits gezahlter Beträge
     * @param prop.roundingAmount Der Betrag, um den der Rechnungsbetrag gerundet wurde.
     * @param prop.amountDueForPayment Der ausstehende Betrag, der zu zahlen ist.
     */
        void setTotalInfo(const DocTotals &prop);

        /**
     *
     * @param prop.taxableAmount Summe aller zu versteuernden Beträge, für die ein bestimmter Code der Umsatzsteuerkategorie und ein
bestimmter Umsatzsteuersatz gelten (falls ein kategoriespezifischer Umsatzsteuersatz gilt)
     * @param prop.taxAmount Der für die betreffende Umsatzsteuerkategorie zu entrichtende Gesamtbetrag.
     * @param prop.VATCategoryCode Codierte Bezeichnung einer Umsatzsteuerkategorie.
     * @param prop.rate Der Umsatzsteuersatz, angegeben als für die betreffende Umsatzsteuerkategorie geltender Prozentsatz.
     Sofern die Rechnung von der Umsatzsteuer ausgenommen ist, ist der Wert "0" zu übermitteln
     * @param prop.reason In Textform angegebener Grund für die Ausnahme des Betrages von der Umsatzsteuerpflicht. Sofern die Umsatzsteuerkategorie AE für die Rechnung gilt, ist hier der Text "Umkehrung der Steuerschuldnerschaft" oder der entsprechende Normtext in der für die Rechnung gewählten Sprache anzugeben.
     * @param prop.reasonCode Ein Code für den Grund für die Ausnahme des Betrages von der Umsatzsteuerpflicht. Die Codeliste VATEX "VAT
exemption reason code list" wird von der Connecting Europe Facility gepflegt und herausgegeben.
     */
        void addVATBreakdown(const VATProp &prop);

        /**
     * 
     * @param prop.reference Eine Kennung der rechnungsbegründenden Unterlage.
     * @param prop.description Eine Beschreibung der rechnungsbegründenden Unterlage.
     * @param prop.location Die Internetadresse bzw. URL (Uniform Resource Locator), unter der das externe Dokument verfügbar ist.
     * @param prop.document Ein als Binärobjekt eingebettetes Anhangsdokument.
     */
        void addAdditionalSupportingDocument(const AdditionalDoc &prop);

        /**
     * 
     * @param line.id Eindeutige Bezeichnung für die betreffende Rechnungsposition
     * @param line.note Ein Textvermerk, der unstrukturierte Informationen enthält, die für die Rechnungsposition maßgeblich sind.
     * @param line.objectId Eine vom Verkäufer angegebene Kennung für ein Objekt, auf das sich die Rechnungsposition bezieht (z. B. Zählernummer, Telefonnummer, Kfz-Kennzeichen, versicherte Person, Abonnement-Nummer, Rufnummer).
     * @param line.quantity Die Menge zu dem in der betreffenden Zeile in Rechnung gestellten Einzelposten (Waren oder Dienstleistungen).
     * @param line.quantityMeasureCode Die für die `quantity` (BT-129) geltende maßeinheit. 
     * @param line.netAmount Der Gesamtbetrag der Rechnungsposition. Dies ist der Betrag ohne Umsatzsteuer, aber einschließlich aller für
die Rechnungsposition geltenden Nachlässe und Abgaben sowie sonstiger anfallender Steuern.
     * @param line.orderReference Eine vom Erwerber ausgegebene Kennung für eine referenzierte Position einer Bestellung/eines Auftrags.
     * @param line.buyerAccountingReference Ein Textwert, der angibt, an welcher Stelle die betreffenden Daten in den Finanzkonten des Erwerbers zu buchen sind.
     * @param line.period Abrechnungszeitraum
     * @param line.allowances Rechnungsposition geltenden Nachlässe.
     * @param line.charges Informationen über Kosten, Zuschläge, und Steuern " ausgenommen die Umsatzsteuer " die für die jeweilige Rechnungsposition gelten
     * @param line.priceDetail Informationen über den Preis für die in der betreffenden Rechnungsposition in Rechnung gestellten Waren und Dienstleistungen.
     * @param line.VATInfo Informationen über die Umsatzsteuer enthalten, die für die in der betreffenden Zeile in Rechnung gestellten Waren und Dienstleistungen.
     * @param line.itemInfo Informationen über die in Rechnung gestellten Waren und Dienstleistungen.
     */
        void addInvoiceLine(const InvoiceLine &line);
    };

    void setLineAllowanceAmount(INVOICE_LINE_ALLOWANCES &lineAllowance, double amount, ISO4217_CurrencyCode currencyCode);
    void setLineAllowanceReason(INVOICE_LINE_ALLOWANCES &lineAllowance, const AllowanceChargeCode &reasonCode, const std::u8string& reasonTxt);
    void setLineAllowanceBaseAmount(INVOICE_LINE_ALLOWANCES &lineAllowance, double amount, ISO4217_CurrencyCode currencyCode);
    void setLineAllowancePercentage(INVOICE_LINE_ALLOWANCES &lineAllowance, double percent);

    void setLineChargeAmount(INVOICE_LINE_CHARGES &lineCharge, double amount, ISO4217_CurrencyCode currencyCode);
    void setLineChargeReason(INVOICE_LINE_CHARGES &lineCharge, const ChargeReasonCode &reasonCode, const std::u8string& reasonTxt);
    void setLineChargeBaseAmount(INVOICE_LINE_CHARGES &lineCharge, double amount, ISO4217_CurrencyCode currencyCode);
    void setLineChargePercentage(INVOICE_LINE_CHARGES &lineCharge, double percent);
}// namespace XRechnung
