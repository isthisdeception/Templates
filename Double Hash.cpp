struct StringHash {
    const int mod1 = 1e9 + 7;
    const int base1 = 131;
    const int mod2 = 1e9 + 9;
    const int base2 = 137;
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
            prefix1[i + 1] = (prefix1[i] * base1 + s[i]) % mod1;
            power1[i + 1] = (power1[i] * base1) % mod1;
            prefix2[i + 1] = (prefix2[i] * base2 + s[i]) % mod2;
            power2[i + 1] = (power2[i] * base2) % mod2;
        }
    }
    
    pair<int, int> get_hash(int l, int r) {
        long long hash1 = (prefix1[r + 1] - (prefix1[l] * power1[r - l + 1]) % mod1 + mod1) % mod1;
        long long hash2 = (prefix2[r + 1] - (prefix2[l] * power2[r - l + 1]) % mod2 + mod2) % mod2;
        return {(int)hash1, (int)hash2};
    }
};