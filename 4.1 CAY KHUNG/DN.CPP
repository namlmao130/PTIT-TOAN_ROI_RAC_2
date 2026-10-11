#include <bits/stdc++.h>
using namespace std;

int t, n ,s;
int a[105][105];
bool visited[105];
vector<pair<int,int>> edges;

void dfs(int u)
{
    visited[u] = 1;
    for(int i = 1;i <= n; i++){
        if(a[u][i] == 1 && !visited[i]){
            edges.push_back({min(u,i),max(u,i)});
            dfs(i);
        }
    }
}

void bfs(int u) {
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 1; i <= n ;i++){
            if(a[v][i] == 1 && !visited[i]){
                edges.push_back({min(v,i),max(v,i)});
                visited[i] =1;
                q.push(i);
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> t >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(visited, false, sizeof(visited));
    edges.clear();
    if(t == 1){
        dfs(s);
        if(edges.size() == n -1){
        cout << edges.size() << endl;
        for(int i = 0; i< edges.size(); i++){
            cout << edges[i].first << " " << edges[i].second << endl;
        }
        }
        else cout << 0;
    }
    if(t == 2){
        bfs(s);
        if(edges.size() == n -1){
        cout << edges.size() << endl;
        for(int i = 0; i< edges.size(); i++){
            cout << edges[i].first << " " << edges[i].second << endl;
        }
        }
        else cout << 0;
    }
    return 0;
}
