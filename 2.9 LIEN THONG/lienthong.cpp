#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[105][105];
bool visited[105];
vector<int> current_comp;
vector<vector<int>> components;

void dfs(int u) {
    visited[u] = true;
    current_comp.push_back(u);

    for (int v = 1; v <= n; ++v) {
        if (a[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
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
        visited[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            current_comp.clear(); // Làm rỗng danh sách đỉnh cho thành phần mới
            dfs(i);               // Gọi DFS để duyệt hết thành phần liên thông chứa đỉnh i

            // Sắp xếp các đỉnh trong thành phần liên thông theo thứ tự tăng dần
            sort(current_comp.begin(), current_comp.end());
            components.push_back(current_comp);
        }
    }

    cout << components.size() << "\n"; // Số lượng thành phần liên thông
    for (int i = 0; i < components.size(); ++i) {
        for (int j = 0; j < components[i].size(); ++j) {
            cout << components[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
