#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
};
int n,s;
int a[105][105];
bool visited[105];

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    visited[s] = 1;
    vector<edge> mst;
    long long weight = 0;
    for(int canh = 1;canh <= n - 1; canh++){
        int min_w = 10000;
        int best_u = -1;
        int best_v = -1;
        for(int u = 1; u <= n;u++){
            if(visited[u]){
                for(int v = 1;v <=n; v++){
                    if(!visited[v] && a[u][v] > 0 && a[u][v] < min_w){
                        min_w = a[u][v];
                        best_u = u;
                        best_v = v;
                    }
                }
            }
        }
        if(min_w == 10000) break;
        weight += min_w;
        visited[best_v] = 1;
        mst.push_back({min(best_u, best_v), max(best_u, best_v), min_w});
    }
    if (mst.size() == n - 1) {
        cout << weight << "\n";
        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << "\n";
        }
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
