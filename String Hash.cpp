struct StringHash {
    const int MOD = 1e9 + 7;   
    const int BASE = 131;   
    vector<int> prefix, power;
    int n;
 
    StringHash(const string &s) {
        n = s.size();
        prefix.resize(n + 1, 0);
        power.resize(n + 1, 1);
 
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] * BASE + s[i]) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }
 
    int get_hash(int l, int r) {
        return (prefix[r + 1] - (prefix[l] * power[r - l + 1]) % MOD + MOD) % MOD;
    }
};