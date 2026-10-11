#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[105][105];
bool visited[105];
vector<int> dinh;

void dfs(int s)
{
    dinh.push_back(s);
    visited[s] = 1;
    for(int v = 1; v <= n; v++){
        if(a[s][v] == 1 && !visited[v]){
            dfs(v);
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
        int dinhBacChan = 0, dinhBacLe = 0;
        for(int i = 1;i <= n;i++){
            int bac = 0;
            for(int j = 1;j <= n;j++){
                cin >> a[i][j];
                bac += a[i][j];
            }
            if(bac %2 == 0) dinhBacChan++;
            else dinhBacLe++;
        }
        memset(visited, false, sizeof(visited));
        dfs(1);
        if(dinh.size() == n && dinhBacChan == n) cout << 1;
        else if(dinh.size() == n && dinhBacLe <= 2) cout << 2;
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
        vector<int> CE; // Lưu chu trình Euler
        st.push(u);

        while (!st.empty()) {
            int s = st.top();
            bool found_edge = false;

            for (int v = 1; v <= n; v++) {
                if (a[s][v] == 1) {
                    st.push(v);
                    a[s][v] = 0; // Đi qua rồi thì XÓA CẠNH
                    a[v][s] = 0;
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
