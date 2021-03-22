#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Segmentree.cpp"
#include "../src/segmentree_definitions/basic_segmentree_operations.cpp"

#include <bits/stdc++.h>
using namespace std;
#define ll long long

TEST_CASE("Segmentree Subsequence Sum")
{
  vector<ll> v = {-2, -3, 4, -1, -2, 1, 5, -3};
  Segmentree<ll, function<ll(ll)>, function<ll(ll, ll)>, function<ll(ll)>, ll> *seg = new Segmentree<ll, function<ll(ll)>, function<ll(ll, ll)>, function<ll(ll)>, ll>(v, number_merge_base, number_merge, number_initializer);
  seg->print_tree();
  REQUIRE(seg->find(0, 7) == -1);
  REQUIRE(seg->find(2, 6) == 7);
  seg->update(3, 3);
  REQUIRE(seg->find(2, 6) == 11);
  seg->update(4, 2);
  REQUIRE(seg->find(2, 6) == 15);
  seg->update(1, 0);
  REQUIRE(seg->find(0, 2) == 2);
}