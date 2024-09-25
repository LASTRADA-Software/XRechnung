include(FetchContent)

fetchcontent_declare(
        Catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG         fa43b77429ba76c462b1898d6cd2f2d7a9416b14 # v3.7.1
)

FetchContent_MakeAvailable(Catch2)

enable_testing()

add_executable(XRechnungTests main.cpp
        minimalRequiredTests.cpp
        utils.hpp
        withDiscountsTests.cpp
        withChargesTests.cpp
        subInvoiceLineTests.cpp)

target_link_libraries(XRechnungTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(XRechnungTests PRIVATE XRechnung)


if (win32)
    add_test(XRechnungTests ./XRechnungTests.exe)
else ()
    add_test(XRechnungTests ./XRechnungTests)
endif ()
