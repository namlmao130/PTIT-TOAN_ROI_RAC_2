#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    int n;
    while (cin >> n) {
        // Ma trận lưu khoảng cách ngắn nhất
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

        // Ma trận lưu vết đường đi: next_node[i][j] lưu đỉnh tiếp theo cần đi từ i để đến j
        vector<vector<int>> next_node(n + 1, vector<int>(n + 1, -1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int w;
                cin >> w;
                if (i == j) {
                    dist[i][j] = 0; // Khoảng cách đến chính nó luôn bằng 0
                } else if (w != 10000) {
                    dist[i][j] = w; // Có cạnh nối
                    next_node[i][j] = j; // Đỉnh tiếp theo trên đường i -> j chính là j
                }
            }
        }

        // BƯỚC 1: THUẬT TOÁN FLOYD-WARSHALL
        // Thử chèn lần lượt từng đỉnh k làm đỉnh trung gian
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    // Nếu có đường từ i -> k và k -> j
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        // Nếu đi vòng qua k ngắn hơn đường hiện tại
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];

                            // Cập nhật lưu vết: Để đi từ i đến j, ta đi theo hướng từ i đến k
                            next_node[i][j] = next_node[i][k];
                        }
                    }
                }
            }
        }

        // BƯỚC 2: TÌM CẶP ĐỈNH (u, v) CÓ ĐƯỜNG ĐI NGẮN NHẤT ĐẠT GIÁ TRỊ MAX
        int max_dist = -1;
        int best_u = -1;
        int best_v = -1;

        // Quét ma trận để tìm max_dist
        // Việc duyệt i, j tăng dần từ 1 -> n kết hợp điều kiện (dist > max_dist)
        // sẽ tự động đảm bảo ưu tiên cặp (u, v) có thứ tự từ điển nhỏ nhất nếu có nhiều cặp bằng giá trị nhau.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && dist[i][j] < INF) {
                    if (dist[i][j] > max_dist) {
                        max_dist = dist[i][j];
                        best_u = i;
                        best_v = j;
                    }
                }
            }
        }

        // BƯỚC 3: IN KẾT QUẢ
        if (max_dist == -1) {
            // Không tìm thấy đường đi nào giữa 2 đỉnh bất kỳ
            cout << 0 << "\n";
        } else {
            // In u, v và độ dài lớn nhất
            cout << best_u << " " << best_v << " " << max_dist << "\n";

            // Truy vết đường đi từ best_u đến best_v
            vector<int> path;
            int curr = best_u;
            while (curr != best_v) {
                path.push_back(curr);
                curr = next_node[curr][best_v];
            }
            path.push_back(best_v);

            // In đường đi
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i < path.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
