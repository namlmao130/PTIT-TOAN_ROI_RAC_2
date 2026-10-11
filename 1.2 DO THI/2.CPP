#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
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
            cout << n << endl;
        for (int i = 0; i < n; i++) {
                int cnt = 0;
                vector<int> ke;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    ke.push_back(j+1);
                    cnt++;
                }
            }
            cout << cnt << " ";
            for(int i : ke) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
