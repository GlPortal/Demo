#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include <catch.hpp>
#include <stdexcept>
#include "../source/Math.cpp"

using namespace std;

struct PlayerFixtures
{

  PlayerFixtures() {
  }

  ~PlayerFixtures() {}

};

TEST_CASE_METHOD(PlayerFixtures, "Transform out of range values") {
  SECTION("Negative out of range gets set to 0") {
    REQUIRE(transformIfNotInRange(-10) == 0);
  }
  SECTION("Out of range gets set to 0") {
    REQUIRE(transformIfNotInRange(10) == 0);
  }
  SECTION("Negative in range gets set to value") {
    REQUIRE(transformIfNotInRange(-30) == -30);
  }
  SECTION("In range gets set to value") {
    REQUIRE(transformIfNotInRange(30) == 30);
  }
  SECTION("Negative in range gets set to value") {
    REQUIRE(transformIfNotInRange(-40) == -40);
  }
  SECTION("In range gets set to value") {
    REQUIRE(transformIfNotInRange(40) == 40);
  }
}

