#include "../../include/segmentree_definitions/basic_segmentree_operations.h"
#define ll long long

ll number_initializer(ll val)
{
  if (val == INT_MIN)
    return 0;
  return val;
}

ll number_merge_base(ll val)
{
  return val;
}

ll number_merge(ll x1, ll x2)
{
  return x1 + x2;
}
