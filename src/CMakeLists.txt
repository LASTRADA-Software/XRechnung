set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME}
            XRechnung.hpp
            XRechnung.cpp
            XRechnungAllowanceChargeCode.hpp
            XRechnungChargeReasonCode.hpp
            XRechnungCountryCode.hpp
            XRechnungCurrencyCode.hpp
            XRechnungEASCode.hpp
            XRechnungMapping.hpp
            XRechnungMeasureUnit.hpp
            XRechnungPaymentMeansCode.hpp
            XRechnungProp.hpp
            XRechnungSerializer.cpp
            XRechnungSerializer.hpp
            XRechnungUtils.hpp
            XRechnungValidator.hpp
)