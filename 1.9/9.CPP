#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;

    int n,m;
    if (t == 1) {
    cin >> n >> m;
    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int x,y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
    }
    for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
        cout << "\n";
    }
    else if (t == 2) {
        cin >> n;
        vector<pair<int, int>> edges;
        edges.push_back({0,0});
        for (int i = 1; i <= n; i++) {
             int k;
             cin >> k;
             for (int j = 0; j < k; j++) {
                  int v;
                  cin >> v;
                  if (i < v) {
                      edges.push_back({i, v});
                  }
             }
        }
        m = edges.size() - 1;
        cout << n << " " << m << "\n";
        vector<vector<int>> B(n + 1, vector<int>(m + 1, 0));
        for (int j = 1; j <= m; j++) {
            B[edges[j].first][j] = 1;
            B[edges[j].second][j] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
