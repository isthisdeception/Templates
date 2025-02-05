#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 binpow(i64 a, i64 b) {
	if (b == 0) {
		return 1;
	}
	i64 res = binpow(a, b / 2);
	if (b % 2 == 1) {
		return res * res * a;
	} else {
		return res * res;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cout << binpow(2, 6) << '\n';
	return 0;
}