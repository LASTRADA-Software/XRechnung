set(CMAKE_CXX_STANDARD 23)

add_library(XRechnung STATIC
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

target_include_directories(XRechnung PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.. $<INSTALL_INTERFACE:include>)
