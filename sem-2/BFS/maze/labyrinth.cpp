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
                field[i][j] = -1;
            }
        }
    }
    size_t x_s, y_s, x_e, y_e = 0;
    std::cin >> y_s >> x_s;
    std::cin >> y_e >> x_e;
    --x_s;
    --x_e;
    --y_s;
    --y_e;
    field[x_s][y_s] = 1;
    q.emplace(x_s, y_s);
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
    std::cout << field[x_e][y_e] - 1;
    return 0;
}