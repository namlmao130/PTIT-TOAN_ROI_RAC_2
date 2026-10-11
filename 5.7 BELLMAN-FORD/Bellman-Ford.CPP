#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    int n, s, t;
    while (cin >> n >> s >> t) {
        vector<Edge> edges;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int w;
                cin >> w;
                if (i != j && w != 10000) {
                    edges.push_back({i, j, w});
                }
            }
        }

        vector<int> dist(n + 1, INF);
        vector<int> trace(n + 1, 0);

        // Khoảng cách đến đỉnh xuất phát luôn là 0
        dist[s] = 0;

        // BƯỚC 1: Thuật toán Bellman-Ford (Lặp N - 1 lần)
        // Đường đi ngắn nhất qua nhiều đỉnh nhất cũng chỉ có N - 1 cạnh
        for (int i = 1; i < n; i++) {
            for (auto edge : edges) {
                // Nếu đỉnh u đã có đường đi tới và việc đi qua u giúp đến v gần hơn
                if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.w;
                    trace[edge.v] = edge.u;
                }
            }
        }

        // BƯỚC 2: Kiểm tra Chu trình âm (Lặp thêm 1 lần nữa)
        // Nếu lặp thêm lần thứ N mà khoảng cách vẫn còn giảm -> Có chu trình âm!
        bool has_negative_cycle = false;
        for (auto edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                has_negative_cycle = true;
                break;
            }
        }

        if (has_negative_cycle) {
            cout << -1 << "\n";
        } else if (dist[t] == INF) {
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
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

