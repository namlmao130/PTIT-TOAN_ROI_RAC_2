#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
int un_a[105][105];
bool visited[105];

void dfs_coHuong(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (a[u][v] == 1 && !visited[v]) {
            dfs_coHuong(v);
        }
    }
}
void dfs_voHuong(int u){
    visited[u] = true;
    for(int v = 1;v <= n;v++){
        if(un_a[u][v] == 1 && !visited[v]){
            dfs_voHuong(v);
        }
    }
}
bool LienThongManh()
{
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= n;j++) visited[j] = 0;
        dfs_coHuong(i);
        for(int j = 1;j <= n;j++){
            if(!visited[j]) return 0;
        }
    }
    return 1;
}
bool LienThongYeu()
{
    for(int i = 1; i <= n; i++) visited[i] = 0;
    dfs_voHuong(1);
    for(int j = 1;j <= n;j++){
            if(!visited[j]) return 0;
        }
    return 1;
}
int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(a[i][j] == 1){
                un_a[i][j] = 1;
                un_a[j][i] = 1;
            }
        }
    }
    if(LienThongManh()) cout << 1;
    else if(!LienThongManh() && LienThongYeu()) cout << 2;
    else cout << 0;
    return 0;
}
