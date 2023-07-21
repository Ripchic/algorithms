#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> adj_matrix[i][j];
        }
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j]) {
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adj_matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}