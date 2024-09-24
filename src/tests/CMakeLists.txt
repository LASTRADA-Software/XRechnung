include(FetchContent)

fetchcontent_declare(
        Catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG         fa43b77429ba76c462b1898d6cd2f2d7a9416b14 # v3.7.1
)

FetchContent_MakeAvailable(Catch2)

set(XRECHNUNG_SAXONHC_LIB "${CMAKE_SOURCE_DIR}/libraries/libsaxon-HEC-windows-12.5.0/libs/win/libsaxon-hec-12.5.0.lib" CACHE PATH "XRechnung: Path to the SaxonHEC library" FORCE)
set(XRECHNUNG_SAXONHC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libraries/libsaxon-HEC-windows-12.5.0")

enable_testing()

include_directories(XRechnungTests PRIVATE ${XRECHNUNG_SAXONHC_INCLUDE_DIR})

add_executable(XRechnungTests main.cpp
        minimalRequiredTests.cpp)

target_link_libraries(XRechnungTests PRIVATE ${XRECHNUNG_SAXONHC_LIB})
target_link_libraries(XRechnungTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(XRechnungTests PRIVATE XRechnung)

file(COPY EN16931-UBL-validation.xslt DESTINATION "${CMAKE_BINARY_DIR}/src/tests")