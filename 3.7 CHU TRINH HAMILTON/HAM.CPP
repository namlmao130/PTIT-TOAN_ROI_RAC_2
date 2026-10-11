#include <bits/stdc++.h>
using namespace std;

int n, u;
int a[105][105];
bool visited[105];
int path[105];
vector<vector<int>> all_paths;

void dfs(int s)
{
    int curr_v = path[s - 1];
    for(int v = 1; v <= n; v++){
        if(a[curr_v][v] == 1 && !visited[v]){
            visited[v] = 1;
            path[s] = v;
        if(s == n){
            if(a[v][u] == 1){
                vector<int> cycle;
                for(int i = 1; i<=n; i++){
                    cycle.push_back(path[i]);
                }
                cycle.push_back(u);
                all_paths.push_back(cycle);
            }
        }
        else dfs(s+1);
        visited[v] = 0;
        }
    }
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    path[1] = u;
    visited[u] = 1;
    dfs(2);
    if (all_paths.empty()) {
        cout << 0 << "\n";
    } else {
        for (int i = 0; i < all_paths.size(); ++i) {
            for (int j = 0; j < all_paths[i].size(); ++j) {
                cout << all_paths[i][j] << " ";
            }
            cout << "\n";
        }
        cout << all_paths.size() << "\n";
    }
    return 0;
}
