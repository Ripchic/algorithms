#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::queue<std::pair<int, int>> q;
    std::cin.tie(nullptr);
    size_t n = 0, m = 0;
    size_t x_s = 0, y_s = 0, x_e = 0, y_e = 0;
    std::cin >> n >> m >> x_s >> y_s >> x_e >> y_e;
    std::vector<std::vector<int>> field(n, std::vector<int>(m, 0));
    --x_s;
    --x_e;
    --y_s;
    --y_e;
    field[x_s][y_s] = 1;
    q.emplace(x_s, y_s);
    std::vector<std::pair<int, int>> possible_steps = {{2,  1},
                                                       {2,  -1},
                                                       {-2, 1},
                                                       {-2, -1},
                                                       {1,  2},
                                                       {1,  -2},
                                                       {-1, 2},
                                                       {-1, -2}};
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [di, dj]: possible_steps) {
            if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
                if (field[i + di][j + dj] == 0) {
                    field[i + di][j + dj] = field[i][j] + 1;
                    q.emplace(i + di, j + dj);
                }
            }
        }
    }
    if (field[x_e][y_e]) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}