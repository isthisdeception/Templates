// generate x amount of random number between l and r
vector<int> get_random(int x, int l, int r) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(l, r);
    vector<int> random;
    random.reserve(x);
    for (int i = 0; i < x; ++i) {
        random.push_back(distrib(gen));
    }
    return random;
}