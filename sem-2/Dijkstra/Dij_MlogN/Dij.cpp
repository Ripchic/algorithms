#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num = 0;
    int ver_num = 0, edg_num = 0;
    std::cin >> num;
    for (size_t i = 0; i < num; ++i) {
        std::cin >> ver_num >> edg_num;
        std::vector<std::vector<std::pair<int, int>>> gr(ver_num);
        for (size_t j = 0; j < edg_num; ++j) {
            int x = 0, y = 0, cost = 0;
            std::cin >> x >> y >> cost;
            gr[x].emplace_back(y, cost);
            gr[y].emplace_back(x, cost);
        }
        int start = 0;
        std::cin >> start;
        std::set<std::pair<int, int>> q;
        const int inf = 1 << 30;
        std::vector<int> dist(ver_num, inf);
        dist[start] = 0;
        q.insert({0, start});
        while (!q.empty()) {
            auto [t_c, v] = *q.begin();
            q.erase(q.begin());
            for (auto [to, w]: gr[v]) {
                if (dist[v] + w < dist[to]) {
                    q.erase({dist[to], to});
                    dist[to] = dist[v] + w;
                    q.insert({dist[to], to});
                }
            }
        }
        for (auto x: dist) {
            if (x == inf) {
                std::cout << 2009000999 << ' ';
            } else {
                std::cout << x << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}