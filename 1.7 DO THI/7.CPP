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
    vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        degree[i] = k;

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            A[i][v] = 1;
        }
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
