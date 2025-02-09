#include <bits/stdc++.h> 
using namespace std;

const int mod = 998244353;

int add(int x, int y) {
    return ((x % mod) + (y % mod)) % mod;
}

int sub(int x, int y) {
    return ((x % mod) - (y % mod) + mod) % mod;
}

int mul(int x, int y) {
    return (1LL * (x % mod) * (y % mod)) % mod;
}

int power(int x, int y) {
    if (y == 0) return 1;
    int res = power(x, y / 2);
    res = 1LL * res * res % mod;
    if (y % 2 == 1) res = 1LL * res * x % mod;
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}


int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cout << divide(1, 2) << '\n';
    cout << power(2, 7) << '\n';

    return 0; 
}