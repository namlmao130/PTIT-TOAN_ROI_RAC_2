#include <iostream>
#include <vector>

using namespace std;

int t, n, u, v;
int a[105][105];
bool visited[105];
int trace[105]; // Mảng lưu vết đường đi: trace[x] = y nghĩa là đi từ y đến x

void dfs(int s) {
    visited[s] = true;
    for (int i = 1; i <= n; ++i) {
        if (a[s][i] == 1 && !visited[i]) {
            trace[i] = s; // Lưu vết: trước đỉnh i là đỉnh s
            dfs(i);
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> t;
    cin >> n >> u >> v;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    if (t == 1) {
        // Yêu cầu 1: Tìm số lượng đường đi ĐỘ DÀI 2 từ u đến v
        // Đường đi độ dài 2 từ u đến v có dạng: u -> k -> v
        int count_paths = 0;
        for (int k = 1; k <= n; ++k) {
            // Nếu có cạnh nối u->k VÀ có cạnh nối k->v
            if (a[u][k] == 1 && a[k][v] == 1) {
                count_paths++;
            }
        }
        cout << count_paths;

    } else if (t == 2) {
        for (int i = 1; i <= n; ++i) {
            visited[i] = false;
            trace[i] = 0;
        }
        dfs(u);
        if (!visited[v]) {
            cout << 0;
        } else {
            // Truy vết ngược từ v về u
            vector<int> path;
            int current = v;
            while (current != u) {
                path.push_back(current);
                current = trace[current];
            }
            path.push_back(u); // Thêm đỉnh xuất phát vào cuối danh sách

            // Vì ta truy vết ngược (từ v -> u) nên phải in đảo ngược lại vector
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << path[i];
                if (i > 0) cout << " ";
            }
        }
    }

    return 0;
}
