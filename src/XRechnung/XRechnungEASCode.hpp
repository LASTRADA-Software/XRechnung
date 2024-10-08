#pragma once
#include <array>
#include <cstdint>

namespace XRechnungUtils {

    // https://www.xrepository.de/details/urn:xoev-de:kosit:codeliste:eas_5
    enum class EASCode : uint16_t {
        Organisationsnummer,
        Siret_Code,
        Ly_Tunnus,
        Data_Universal_Numbering_System_DUNS_Number,
        Ean_Location_Code,
        Danish_Chamber_Of_Commerce_Scheme_Edira_Compliant,
        Fti_Ediforum_Italia_Edira_Compliant,
        Vereniging_Van_Kamers_Van_Koophandel_En_Fabrieken_In_Nederland_Association_Of_Chambers_Of_Commerce_And_Industry_In_The_Netherlands_Scheme_Edira_Compliant,
        Directorates_Of_The_European_Commission,
        Sia_Object_Identifiers,
        Seceti_Object_Identifiers,
        Standard_Company_Code,
        Australian_Business_Number_Abn_Scheme,
        Teikoku_Company_Code,
        Numerro_Didentification_Suisse_Des_Enterprises_Ide_Swiss_Unique_Business_Identification_Number_Uidb,
        Digstorg,
        Corporate_Number_Of_The_Social_Security_And_Tax_Number_System,
        Dutch_Originators_Identification_Number,
        Centre_Of_Registers_And_Information_Systems_Of_The_Ministry_Of_Justice,
        Enhetsregisteret_Ved_Bronnoysundregisterne,
        Ublbe_Party_Identifier,
        Koios_Open_Technical_Dictionary,
        Singapore_Uen_Identifier,
        Kennitala_Iceland_Legal_Id_For_Individuals_And_Legal_Entities,
        Erstorg,
        Legal_Entity_Identifier_Lei,
        Legal_Entity_Code_Lithuania,
        Codice_Univoco_Unite_Organizzativa_Ipa,
        Indirizzo_Di_Posta_Elettronica_Certificata,
        Edelivery_Network_Participant_Identifier,
        Leitweg_Id,
        Coddest,
        Numero_Dentreprise_Ondernemingsnummer_Unternehmensnummer,
        Gs1_Identification_Keys,
        Codice_Fiscale,
        Partita_Iva,
        Finnish_Organization_Identifier,
        Finnish_Organization_Value_Add_Tax_Identifier,
        Net_Service_Id,
        Ovtcode,
        Danish_Ministry_Of_The_Interior_And_Health,
        The_Danish_Commerce_And_Companies_Agency,
        Danish_Ministry_Of_Taxation_Central_Customs_And_Tax_Administration,
        Danish_Vans_Providers,
        Ufficio_Responsabile_Gestione_Partite_Iva,
        Tax_Authority,
        Hungary_Vat_Number,
        Business_Registers_Network,
        Oesterreichische_Umsatzsteuer_Identifikationsnummer,
        Oesterreichisches_Verwaltungs_Bzw_Organisationskennzeichen,
        Kennitala_Iceland_Legal_Id_For_Organizations_And_Individuals,
        Society_For_Worldwide_Interbank_Financial_Telecommunication_Swift,
        Kennziffer_Des_Unternehmensregisters,
        Agencia_Espanola_De_Administracion_Tributaria,
        Indice_Delle_Pubbliche_Amministrazioni,
        Andorra_Vat_Number,
        Albania_Vat_Number,
        Bosnia_And_Herzegovina_Vat_Number,
        Belgium_Vat_Number,
        Bulgaria_Vat_Number,
        Switzerland_Vat_Number,
        Cyprus_Vat_Number,
        Czech_Republic_Vat_Number,
        Germany_Vat_Number,
        Estonia_Vat_Number,
        United_Kingdom_Vat_Number,
        Greece_Vat_Number,
        Croatia_Vat_Number,
        Ireland_Vat_Number,
        Liechtenstein_Vat_Number,
        Lithuania_Vat_Number,
        Luxemburg_Vat_Number,
        Latvia_Vat_Number,
        Monaco_Vat_Number,
        Montenegro_Vat_Number,
        Macedonia_The_Former_Yugoslav_Republic_Of_Vat_Number,
        Malta_Vat_Number,
        Netherlands_Vat_Number,
        Poland_Vat_Number,
        Portugal_Vat_Number,
        Romania_Vat_Number,
        Serbia_Vat_Number,
        Slovenia_Vat_Number,
        Slovakia_Vat_Number,
        San_Marino_Vat_Number,
        Turkey_Vat_Number,
        Holy_See_Vatican_City_State_Vat_Number,
        Swedish_Vat_Number,
        Belgian_Crossroad_Bank_Of_Enterprises,
        French_Vat_Number,
        German_Leitweg_Id,
        Oftp_Odette_File_Transfer_Protocol,
        X400_Address_For_Mail_Text,
        As2_Exchange,
        File_Transfer_Protocol,
        Electronic_Mail,
        Digaveid,
        Freischaltcode,
        Ik
    };

    static constexpr std::array<std::u8string_view, 100> EASCodes{
            u8"0002",
            u8"0007",
            u8"0009",
            u8"0037",
            u8"0060",
            u8"0088",
            u8"0096",
            u8"0097",
            u8"0106",
            u8"0130",
            u8"0135",
            u8"0142",
            u8"0147",
            u8"0151",
            u8"0170",
            u8"0183",
            u8"0184",
            u8"0188",
            u8"0190",
            u8"0191",
            u8"0192",
            u8"0193",
            u8"0194",
            u8"0195",
            u8"0196",
            u8"0198",
            u8"0199",
            u8"0200",
            u8"0201",
            u8"0202",
            u8"0203",
            u8"0204",
            u8"0205",
            u8"0208",
            u8"0209",
            u8"0210",
            u8"0211",
            u8"0212",
            u8"0213",
            u8"0215",
            u8"0216",
            u8"9901",
            u8"9902",
            u8"9904",
            u8"9905",
            u8"9906",
            u8"9907",
            u8"9910",
            u8"9913",
            u8"9914",
            u8"9915",
            u8"9917",
            u8"9918",
            u8"9919",
            u8"9920",
            u8"9921",
            u8"9922",
            u8"9923",
            u8"9924",
            u8"9925",
            u8"9926",
            u8"9927",
            u8"9928",
            u8"9929",
            u8"9930",
            u8"9931",
            u8"9932",
            u8"9933",
            u8"9934",
            u8"9935",
            u8"9936",
            u8"9937",
            u8"9938",
            u8"9939",
            u8"9940",
            u8"9941",
            u8"9942",
            u8"9943",
            u8"9944",
            u8"9945",
            u8"9946",
            u8"9947",
            u8"9948",
            u8"9949",
            u8"9950",
            u8"9951",
            u8"9952",
            u8"9953",
            u8"9955",
            u8"9956",
            u8"9957",
            u8"9958",
            u8"AN",
            u8"AQ ",
            u8"AS ",
            u8"AU ",
            u8"EM",
            u8"XR01",
            u8"XR02",
            u8"XR03"};

    inline std::u8string getEASCode(const EASCode &code) {
        if (const auto idx = static_cast<size_t>(code); idx < EASCodes.size())
            return EASCodes.at(idx).data();
        return u8"";
    }
}// namespace XRechnungUtils
