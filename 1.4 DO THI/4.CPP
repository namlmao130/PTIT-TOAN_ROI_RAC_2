#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP","r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin>> t;

    int n, m;
    cin >> n >> m;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
        cout << "\n";
    }
    else if (t == 2) {
        cout << n << "\n";

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
