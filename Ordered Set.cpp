// do not use #define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to k-th element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// to make descending, greater<T>

ordered_set<pair<int, int>> st; // for multiset use pair
