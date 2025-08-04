const int N = 1E7 + 5;
vector<bool> is_prime(N, 1);
void pre() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}