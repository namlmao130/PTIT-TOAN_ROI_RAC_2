#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
bool visited[105];

void dfs(int u)
{
    visited[u] = 1;
    for(int v = 1; v <= n; v++){
        if(a[u][v] == 1 && !visited[v]){
            dfs(v);
        }
    }
}

int count_components()
{
    memset(visited, false, sizeof(visited));
    int comp = 0;
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            dfs(i);
            comp++;
        }
    }
    return comp;
}
int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    memset(visited,false,sizeof(visited));
    vector<pair<int,int>> edges;
    for(int i = 1;i <=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> a[i][j];

            if(a[i][j] == 1 && i<j){
                edges.push_back({i,j});
            }
        }
    }
    int component = count_components();
    vector<pair<int,int>> bridges;
    int comp = 0;
    for(int i = 0; i<= edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        a[u][v] = 0;
        a[v][u] = 0;
        int t = count_components();

        if(t > component) bridges.push_back({u,v});

        a[u][v] = 1;
        a[v][u] = 1;
    }
    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << endl;
    for(int i = 0 ;i < bridges.size(); i++){
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
    return 0;
}
