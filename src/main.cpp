#include <bits/stdc++.h>
#include "Segmentree.cpp"
#include "segmentree_definitions/basic_segmentree_operations.cpp"

using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<ll> v = {-2, -3, 4, -1, -2, 1, 5, -3};
  Segmentree<ll,
             function<ll(ll)>,
             function<ll(ll, ll)>,
             function<ll(ll)>,
             ll>
      basic_segmentree(v, number_merge_base, number_merge, number_initializer);
  basic_segmentree.print_tree();
  basic_segmentree.find(0, 7);
  basic_segmentree.update(3, 2);
  basic_segmentree.print_tree();
  basic_segmentree.find(0, 7);
  return 0;
}