#include <XRechnung/XRechnungUtils.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("EscapeCharacters", "[XRechnung][Utils]")
{
    SECTION("less than replace")
    {
        const std::string tmp = "lorem ipsum < 25km";
        REQUIRE(XRechnungUtils::escapeSpecialChars(tmp) == "lorem ipsum &lt; 25km");
    }

    SECTION("greater than replace")
    {
        const std::string tmp = "lorem ipsum > 25km";
        REQUIRE(XRechnungUtils::escapeSpecialChars(tmp) == "lorem ipsum &gt; 25km");
    }

    SECTION("ampersand replace")
    {
        const std::string tmp = "lorem ipsum & samit dolor";
        REQUIRE(XRechnungUtils::escapeSpecialChars(tmp) == "lorem ipsum &amp; samit dolor");
    }

    SECTION("quote replace")
    {
        const std::string tmp = "lorem ipsum \"samit\" dolor";
        REQUIRE(XRechnungUtils::escapeSpecialChars(tmp) == "lorem ipsum &quot;samit&quot; dolor");
    }

    SECTION("apostrophe replace")
    {
        const std::string tmp = "lorem ipsum dolor l'access";
        REQUIRE(XRechnungUtils::escapeSpecialChars(tmp) == "lorem ipsum dolor l&apos;access");
    }
}