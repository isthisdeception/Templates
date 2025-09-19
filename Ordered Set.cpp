// do not use #define int long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// s.insert(x) → insert element x.
// s.erase(x) → erase element x.
// *s.find_by_order(k) → k-th smallest element (0-indexed).
// s.order_of_key(x) → number of elements strictly smaller than x.
// to make descending, greater<T>

ordered_set<pair<int, int>> s; // for multiset use pair
