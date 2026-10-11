#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, s, t;
int c[105][105];

void dijkstra() {
    vector<int> dist(n + 1, INF);   // Mảng lưu khoảng cách ngắn nhất từ s đến các đỉnh
    vector<bool> visited(n + 1, false);
    vector<int> trace(n + 1, 0);
    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        // Bước 1: Tìm đỉnh u chưa được thăm có khoảng cách (dist) nhỏ nhất
        int u = -1;
        int min_d = INF;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min_d) {
                min_d = dist[j];
                u = j;
            }
        }

        // Nếu không tìm được đỉnh nào hoặc đỉnh nhỏ nhất vẫn là vô cực -> Đồ thị đứt đoạn
        if (u == -1 || min_d == INF) break;

        // Chốt đỉnh u
        visited[u] = true;

        // Nếu đã chốt được khoảng cách ngắn nhất đến đích t thì có thể dừng sớm (tối ưu)
        if (u == t) break;

        // Bước 2: Dùng đỉnh u để tối ưu (relax) khoảng cách tới các đỉnh kề v
        for (int v = 1; v <= n; v++) {
            // Chỉ xét nếu có cạnh nối hợp lệ (trọng số < 10000 và > 0)
            if (!visited[v] && c[u][v] > 0 && c[u][v] < 10000) {
                if (dist[u] + c[u][v] < dist[v]) {
                    dist[v] = dist[u] + c[u][v];
                    trace[v] = u; // Lưu vết: Để đến được v ngắn nhất, phải đi qua u
                }
            }
        }
    }
    if (dist[t] == INF) {
        cout << 0 << "\n";
    } else {
        cout << dist[t] << "\n";

        vector<int> path;
        int curr = t;
        while (curr != 0) {
            path.push_back(curr);
            curr = trace[curr];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    while (cin >> n >> s >> t) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> c[i][j];
            }
        }
        dijkstra();
    }

    return 0;
}

