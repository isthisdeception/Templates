const int N = 1E5 + 5;
vector<int> spf(N + 5, 0);
 
void seive() {
    for (int i = 1; i <= N; ++i) {
        spf[i] = i;
    }
    for (int i = 2; i <= N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
 
vector<int> get_factors(int x) {
    vector<int> primes;
    while (x > 1) {
        primes.push_back(spf[x]);
        x /= spf[x];
    }
    return primes;
}