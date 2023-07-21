#include <iostream>
#include <vector>
#include <algorithm>
#include "set"

int main() {
    int n = 0, s = 0, f = 0;
    std::cin >> n >> s >> f;
    --s;
    --f;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<std::vector<std::pair<int, int>>> gr(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            if (i == j || x == -1) {
                continue;
            }
            gr[i].emplace_back(j, x);
        }
    }
    std::set<std::pair<int, int>> q;
    const int inf = 1 << 30;
    std::vector<int> dist(n, inf);
    dist[s] = 0;
    q.insert({0, s});
    while (!q.empty()) {
        auto [r, cur] = *q.begin();
        q.erase(q.begin());
        for (auto [to, w]: gr[cur]) {
            if (dist[cur] + w < dist[to]) {
                if (dist[to] != inf) {
                    q.erase(q.find({dist[to], to}));
                }
                dist[to] = dist[cur] + w;
                q.insert({dist[to], to});
            }
        }
    }
    if (dist[f] == inf) {
        std::cout << -1;
    } else {
        std::cout << dist[f];
    }
    return 0;
}