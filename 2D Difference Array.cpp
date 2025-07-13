#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k <= 0) {
        cout << "k must be a positive integer." << endl;
        return 1;
    }
    if (k > n || k > m) {
        cout << "k cannot be larger than n or m." << endl;
        return 1;
    }
    vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n - k; ++i) { 
        for (int j = 0; j <= m - k; ++j) { 
            int r1 = i, c1 = j;
            int r2 = i + k - 1;
            int c2 = j + k - 1;
            diff[r1][c1] += 1;
            if (r2 + 1 < n + 1) {
                diff[r2 + 1][c1] -= 1;
            }
            if (c2 + 1 < m + 1) { 
                diff[r1][c2 + 1] -= 1;
            }
            if (r2 + 1 < n + 1 && c2 + 1 < m + 1) { 
                diff[r2 + 1][c2 + 1] += 1;
            }
        }
    }
    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            r[i][j] = diff[i][j];
            if (i > 0) r[i][j] += r[i - 1][j];
            if (j > 0) r[i][j] += r[i][j - 1];
            if (i > 0 && j > 0) r[i][j] -= r[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << r[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}