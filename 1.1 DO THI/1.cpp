#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    if (!(cin >> t >> n)) return 0;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    if (t == 1) {
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                degree += A[i][j];
            }
            cout << degree << " ";
        }
        cout << "\n";
    }
    else if (t == 2) {
        vector<pair<int, int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i][j] == 1) {
                    edges.push_back({i + 1, j + 1});
                }
            }
        }

        cout << n << " " << edges.size() << "\n";
        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }

    return 0;
}
