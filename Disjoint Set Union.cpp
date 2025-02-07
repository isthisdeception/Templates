#include <bits/stdc++.h> 
using namespace std;

struct DSU {
    vector<int> f, sz;
    int n;

    DSU () = default;
    DSU (int _n): n(_n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
    }

    int Find(int v) {
        if (f[v] == v) {
            return v;
        } else {
            return f[v] = Find(f[v]);
        }
    }

    bool Union(int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        f[u] = v;
        sz[v] += sz[u];
        return true;;
    }

    bool Same(int u, int v) {
        return Find(u) == Find(v);
    }
};

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n = 1;
    DSU dsu(n);

    return 0; 
}