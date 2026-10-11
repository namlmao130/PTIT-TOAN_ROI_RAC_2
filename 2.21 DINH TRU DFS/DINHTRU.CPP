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

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        visited[i] = 0;
    }
    for(int i = 1;i <=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    int comp = 0;
    for(int i = 1; i <= n;i++){
        if(!visited[i]){
            dfs(i);
            comp++;
        }
    }

    vector<int> Articulation_Point;
    for(int i = 1; i<= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = 1;
        int t = 0;
        for(int j =1;j <= n;j++){
            if(!visited[j]){
                dfs(j);
                t++;
            }
        }
        if(t > comp) Articulation_Point.push_back(i);
    }
    cout << Articulation_Point.size() << endl;
    for(int i = 0 ;i < Articulation_Point.size(); i++){
        cout << Articulation_Point[i] << " ";
    }
    return 0;
}
