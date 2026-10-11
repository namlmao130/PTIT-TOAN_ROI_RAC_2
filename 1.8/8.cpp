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

    int n;
    cin >> n;

    vector<int> degree(n + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        degree[i] = k;

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            if (i < v) {
                edges.push_back({i, v});
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
        cout << "\n";
    }
    else if (t == 2) {
        cout << n << " " << edges.size() << "\n";
        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }

    return 0;
}
