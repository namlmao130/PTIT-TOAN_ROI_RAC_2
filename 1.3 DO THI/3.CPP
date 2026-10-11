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
        vector<pair<int,int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (A[i][j] == 1) {
                    edges.push_back({i,j});
                }
            }
        }
        int m = edges.size();
        vector<vector<int>> LienThuoc(n,vector<int>(m,0));
        for(int i = 0;i < m;i++){
            int u = edges[i].first;
            int v = edges[i].second;
            LienThuoc[u][i] = 1;
            LienThuoc[v][i] = 1;
        }
        cout << n << " " << m << endl;
        for(int i = 0; i< n;i++){
            for(int j : LienThuoc[i])
                cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
