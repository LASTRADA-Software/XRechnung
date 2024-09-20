#  XRechnung DIN CEN TS 16931-3-1_2018
Cpp project after the specification in DIN CEN TS 16931-3-1_2018

## Usage
the important file for you will be the `src/XRechnung.hpp`
```c++
#include "XRechnung/XRechnung.hpp"
```
when included you can use the `Invoice` class inside the `namespace XRechnung`.
```c++
  using namespace XRechnungUtils;

  auto jpBoRechnung = JpBoRechnung();
```

### Enums from different [Codelists](#Codelists) 
they are available in the namespace `XRechnungUtils`
- ISO4217_CurrencyCode
- EASCode
- MEASURE_UNIT
- PaymentMeanCode
- ChargeReasonCode
- AllowanceChargeCode

Please create a conversion function for your specific needs.
```c++
[[ nodiscard ]] XRechnungUtils::MEASURE_UNIT convertToMeasureUnit(const std::string &val)
{
  if (val == "pc")
    return XRechnungUtils::MEASURE_UNIT::Piece;
  if (val == "stk")
    return XRechnungUtils::MEASURE_UNIT::Each;
  if (val == "hrs")
    return XRechnungUtils::MEASURE_UNIT::Hour;
  ...
  // default case
  return XRechnungUtils::MEASURE_UNIT::Mutually_Defined;
}
```

### Codelists

| Name                             | Beschreibung                                                                                                                 | Version | XRepository Versionskennung und Link         |
|----------------------------------|------------------------------------------------------------------------------------------------------------------------------|---------|----------------------------------------------|
| ISO 3166-1                       | Country codes  (kompatibel zu ISO 3166-1)                                                                                    | 2022    | urn:xoev-de:kosit:codeliste:country-codes_8  |
| ISO 4217                         | Currency codes (kompatibel zu ISO4217)                                                                                       | 2021    | urn:xoev-de:kosit:codeliste:currencycodes_3  |
| UNTDID 1001                      | Document name code                                                                                                           | d21a    | urn:xoev-de:kosit:codeliste:untdid.1001_4    |
| UNTDID 1153                      | Reference code qualifier                                                                                                     | d20a    | urn:xoev-de:kosit:codeliste:untdid.1153_3    |
| UNTDID 2005                      | Date or time or period function code qualifier                                                                               | d21a    | urn:xoev-de:kosit:codeliste:untdid.2005_4    |
| UNTDID 4451                      | Text subject code qualifier                                                                                                  | d21a    | urn:xoev-de:kosit:codeliste:untdid.4451_4    |
| UNTDID 4461                      | Payment means code                                                                                                           | d20a    | urn:xoevde:xrechnung:codeliste:untdid.4461_3 |
| UNTDID 5189                      | Allowance or charge identification code                                                                                      | d20a    | urn:xoev-de:kosit:codeliste:untdid.5189_3    |
| UNTDID 5305                      | Duty or tax or fee category code                                                                                             | d20a    | urn:xoev-de:kosit:codeliste:untdid.5305_3    |
| UNTDID 7143                      | Item type identification code                                                                                                | d21a    | urn:xoev-de:kosit:codeliste:untdid.7143_4    |
| UNTDID 7161                      | Special service description code                                                                                             | d20a    | urn:xoev-de:kosit:codeliste:untdid.7161_3    |
| ICD                              | Identifier scheme code (kompatibel zu ISO 6523)                                                                              | 2023    | urn:xoev-de:kosit:codeliste:icd_5            |
| EAS                              | Electronic Address Scheme Code list                                                                                          | 9.0     | urn:xoev-de:kosit:codeliste:eas_5            |
| VATEX VAT                        | exemption reason code list                                                                                                   | 4.0     | urn:xoev-de:kosit:codeliste:vatex_1          |
| Rec 20 UN/EC Recommendation Nº20 | Codes for Units of Measure Used in International Trade Revision                                                              | 17      | urn:xoev-de:kosit:codeliste:rec20_3          |
| Rec 21 UN/EC Recommendation Nº21 | Codes for Passengers, Types of Cargo, Packages and Packaging Materials (with Complementary Codes for Package Names) Revision | 12      | urn:xoev-de:kosit:codeliste:rec21_3          |

