#include <bits/stdc++.h> 
using namespace std;

const int N = 1E6 + 5;
int spf[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; ++i) {
        spf[i] = i;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }

    int q; 
    cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> prime_fact;
        while (n > 1) {
            prime_fact.push_back(spf[n]);
            n /= spf[n];
        }
        for (auto p: prime_fact) {
            cout << p << ' ';
        }
        cout << '\n';
    }

    return 0; 
}
