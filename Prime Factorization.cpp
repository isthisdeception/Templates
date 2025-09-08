auto prime_fact(int n) {
    vector<pair<int, int>> f;
    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    if (cnt > 0) f.emplace_back(2, cnt);
    for (int i = 3; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            if (cnt > 0) f.emplace_back(i, cnt);
        }
    }
    if (n > 1) f.emplace_back(n, 1);
    return f;
}
// works up to around 1e12 comfortably