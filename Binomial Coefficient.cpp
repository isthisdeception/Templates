#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int fact[N], ifact[N];

int power(int a, int b) {
	if (b == 0) return 1;
	int res = power(a, b / 2);
	res = 1LL * res * res % mod;
	if (b % 2 == 1) res = 1LL * res * a % mod;
	return res;
}

int inverse(int n) {
	return power(n, mod - 2);
}

void prec() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = 1LL * fact[i - 1] * i % mod;
	}
	ifact[N - 1] = inverse(fact[N - 1]);
	for (int i = N - 2; i >= 0; --i) {
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
	}
}

int nCr(int n, int r) {
	if (n < r) return 0;
	return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
	if (n < r) return 0;
	return 1LL * fact[n] * ifact[n - r] % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	prec();
	cout << nCr(5, 3) << '\n';
	
	return 0;
}
