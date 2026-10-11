#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
bool visited[105];

void bfs(int s)
{
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 1;v <= n;v++){
            if(a[u][v] == 1 && !visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int comp = 0;
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            bfs(i);
            comp++;
        }
    }
    vector<int> dinhTru;
    for(int i = 1;i <=n;i++){
        memset(visited, false, sizeof(visited));
        visited[i] = 1;
        int t= 0;
        for(int j = 1;j <= n;j++){
            if(!visited[j]) {
                bfs(j);
                t++;
            }
        }
        if(t > comp) dinhTru.push_back(i);
    }
    cout << dinhTru.size() << endl;
    for(int i = 0;i < dinhTru.size(); i++){
        cout << dinhTru[i] << " ";
    }
    return 0;
}
