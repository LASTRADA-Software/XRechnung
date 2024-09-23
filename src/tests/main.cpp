#include "catch2/catch_session.hpp"


int main(int argc, char *argv[])
{
    // your setup ...

    int result = Catch::Session().run(argc, argv);

    // your clean-up...
    // on the CI the ./scripts/docker-shutdown.ps1 will be run automatically
    // if we would do this locally too we would lose some time because we would need to re-create the container again and again

    return result;
}
