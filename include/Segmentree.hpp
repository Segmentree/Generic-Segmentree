#include <bits/stdc++.h>

using namespace std;
#define ll long long

template <typename T, typename MB, typename M, typename OI, typename R>
class Segmentree
{
private:
  T *tree;
  MB merge_base;
  M merge;
  OI object_initializer;
  ll size;
  ll tree_nodes;
  R find_engine(ll v, ll tl, ll tr, ll l, ll r);
  void init_leafs();
  void print(ll i, bool is_left, string prefix, function<void(T)> print);

public:
  Segmentree(vector<ll> &arr, MB mb, M m, OI oi);
  R find(ll i, ll j);
  void update(ll k, ll val);
  void print_tree(function<void(T)> print = [](T obj) { cout << obj << "\n"; });
};