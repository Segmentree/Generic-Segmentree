#include <bits/stdc++.h>
#include "../include/Segmentree.hpp"

using namespace std;
#define ll long long

template <typename T, typename MB, typename M, typename OI, typename R>
Segmentree<T, MB, M, OI, R>::Segmentree(vector<ll> &arr, MB mb, M m, OI oi)
{
  merge_base = mb;
  merge = m;
  object_initializer = oi;
  size = pow(2, (long long)(ceil(log2(arr.size()))));
  tree_nodes = pow(2, (long long)(ceil(log2(size))) + 1);
  tree = new T[tree_nodes];
  init_leafs();
  for (ll i = 0; i < arr.size(); ++i)
  {
    update(i, arr[i]);
  }
}

template <typename T, typename MB, typename M, typename OI, typename R>
void Segmentree<T, MB, M, OI, R>::init_leafs()
{
  for (ll i = 1; i < tree_nodes; ++i)
  {
    tree[i] = object_initializer(INT_MIN);
  }
}

template <typename T, typename MB, typename M, typename OI, typename R>
R Segmentree<T, MB, M, OI, R>::find_engine(ll v, ll tl, ll tr, ll l, ll r)
{
  if (l > r)
    return object_initializer(INT_MIN);
  if (l == tl && r == tr)
  {
    return merge_base(tree[v]);
  }
  ll tm = (tl + tr) / 2;
  return merge(find_engine(v * 2, tl, tm, l, min(r, tm)),
               find_engine(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

template <typename T, typename MB, typename M, typename OI, typename R>
R Segmentree<T, MB, M, OI, R>::find(ll i, ll j)
{
  return find_engine(1, 0, size - 1, i, j);
}

template <typename T, typename MB, typename M, typename OI, typename R>
void Segmentree<T, MB, M, OI, R>::update(ll k, ll val)
{
  k += size;
  tree[k] = object_initializer(val);
  for (k /= 2; k >= 1; k /= 2)
  {
    tree[k] = merge(tree[2 * k], tree[2 * k + 1]);
  }
}

template <typename T, typename MB, typename M, typename OI, typename R>
void Segmentree<T, MB, M, OI, R>::print(ll i, bool is_left, string prefix, function<void(T)> _print)
{
  if (i >= tree_nodes)
    return;
  cout << prefix;
  cout << (is_left ? "├──" : "└──");
  _print(tree[i]);
  print(i * 2, true, prefix + (is_left ? "│   " : "    "), _print);
  print(i * 2 + 1, false, prefix + (is_left ? "│   " : "    "), _print);
}

template <typename T, typename MB, typename M, typename OI, typename R>
void Segmentree<T, MB, M, OI, R>::print_tree(function<void(T)> _print)
{
  print(1, false, "", _print);
  cout << "\n";
}