struct StringHash {
    const int MOD1 = 1e9 + 7;
    const int BASE1 = 131;
    const int MOD2 = 1e9 + 9;
    const int BASE2 = 137;
    int n;
    vector<long long> prefix1, power1;
    vector<long long> prefix2, power2;
    
    StringHash(const string &s) {
        n = s.size();
        prefix1.resize(n + 1, 0);
        power1.resize(n + 1, 1);
        prefix2.resize(n + 1, 0);
        power2.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            prefix1[i + 1] = (prefix1[i] * BASE1 + s[i]) % MOD1;
            power1[i + 1] = (power1[i] * BASE1) % MOD1;
            prefix2[i + 1] = (prefix2[i] * BASE2 + s[i]) % MOD2;
            power2[i + 1] = (power2[i] * BASE2) % MOD2;
        }
    }
    
    pair<int, int> get_hash(int l, int r) {
        long long hash1 = (prefix1[r + 1] - (prefix1[l] * power1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        long long hash2 = (prefix2[r + 1] - (prefix2[l] * power2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {(int)hash1, (int)hash2};
    }
};