set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

fetchcontent_declare(
        Catch2
        GIT_REPOSITORY  https://github.com/catchorg/Catch2.git
        GIT_TAG         fa43b77429ba76c462b1898d6cd2f2d7a9416b14 # v3.7.1
)

FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(XRechnungTests main.cpp
        minimalRequiredTests.cpp)

target_link_libraries(XRechnungTests PRIVATE C:/Users/f.eisenmenger/CLionProjects/XRechnung/libraries/libsaxon-HEC-windows-12.5.0/libs/win/libsaxon-hec-12.5.0.lib)
target_link_libraries(XRechnungTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(XRechnungTests PRIVATE XRechnung)