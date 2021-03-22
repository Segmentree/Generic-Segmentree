#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/fact.cpp"

TEST_CASE("Factorials are computed", "[factorial]")
{
  REQUIRE(Factorial(0) == 1);
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(4) == 24);
  REQUIRE(Factorial(5) == 120);
  REQUIRE(Factorial(10) == 3628800);
}