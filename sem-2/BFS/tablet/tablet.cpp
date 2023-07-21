#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::queue<std::pair<int, int>> q;
    std::cin.tie(nullptr);
    size_t n, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> field(n, std::vector<int>(m, 0));
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[0].size(); ++j) {
            std::cin >> field[i][j];
            if (field[i][j] == 1) {
                q.emplace(i, j);
            }
        }
    }
    std::vector<std::pair<int, int>> possible_steps = {{-1, 0},
                                                       {1,  0},
                                                       {0,  -1},
                                                       {0,  1}};

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [di, dj]: possible_steps) {
            if (i + di >= 0 && i + di < field.size() && j + dj >= 0 && j + dj < field[0].size()) {
                if (field[i + di][j + dj] == 0) {
                    field[i + di][j + dj] = field[i][j] + 1;
                    q.emplace(i + di, j + dj);
                }
            }
        }
    }
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[0].size(); ++j) {
            std::cout << field[i][j] - 1 << ' ';
        }
        std::cout << "\n";
    }
    return 0;
}