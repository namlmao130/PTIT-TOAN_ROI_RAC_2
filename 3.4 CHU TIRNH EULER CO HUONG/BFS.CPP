#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[105][105];
int deg_in[105] = {0};
int deg_out[105] = {0};
bool visited[105];
vector<int> dinh;

void bfs(int s)
{
    dinh.push_back(s);
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1; v <= n; v++){
             if(a[s][v] == 1 && !visited[v]){
                visited[v] = 1;
                bfs(v);
             }
        }
    }
}

int main()
{
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t;

    if(t == 1){
        cin >> n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cin >> a[i][j];
                if(a[i][j] == 1){
                   deg_in[j]++;
                   deg_out[i]++;
                }
            }
        }
        memset(visited, false, sizeof(visited));
        bfs(1);
        int cnt =0;
        for(int i = 1;i <= n ;i++){
            if(abs(deg_in[i] - deg_out[i]) == 1) cnt++;
        }
        if(dinh.size() == n && cnt == 0) cout << 1;
        else if(dinh.size() == n && cnt <= 2) cout << 2;
        else cout << 0;
    }
    if(t == 2){
        int u;
        cin >> n >> u;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cin >> a[i][j];
            }
        }
        stack<int> st;
        vector<int> CE;
        st.push(u);

        while (!st.empty()) {
            int s = st.top();
            bool found_edge = false;

            for (int v = 1; v <= n; v++) {
                if (a[s][v] == 1) {
                    st.push(v);
                    a[s][v] = 0;
                    found_edge = true;
                    break;
                }
            }

            if (!found_edge) {
                st.pop();
                CE.push_back(s);
            }
        }

        for (int i = CE.size() - 1; i >= 0; i--) {
            cout << CE[i];
            if (i > 0) cout << " ";
        }
    }
    return 0;
}
