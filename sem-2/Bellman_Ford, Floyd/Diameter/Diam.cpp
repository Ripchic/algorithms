#include <iostream>
#include <vector>
#include <limits>

const int inf = std::numeric_limits<int>::max();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> adj_matrix[i][j];
            if (adj_matrix[i][j] == -1) {
                adj_matrix[i][j] = inf;
            }
        }
    }

    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (adj_matrix[i][k] != inf && adj_matrix[k][j] != inf) {
                    adj_matrix[i][j] = std::min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                }
            }
        }
    }

    int diam = 0;
    int rad = inf;
    for (size_t i = 0; i < n; ++i) {
        int max_dist = 0;
        for (size_t j = 0; j < n; ++j) {
            if (adj_matrix[i][j] != inf) {
                max_dist = std::max(max_dist, adj_matrix[i][j]);
            }
        }
        diam = std::max(diam, max_dist);
        rad = std::min(rad, max_dist);
    }
    std::cout << diam << '\n' << rad;

    return 0;
}