#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    if (!(cin >> t)) return 0;

    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);
    vector<vector<int>> B(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        degree[u]++;
        degree[v]++;

        B[u][i] = 1;
        B[v][i] = 1;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
        cout << "\n";
    }
    else if (t == 2) {
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
