#include <iostream>
#include <vector>
#include <set>
#include <functional>

struct Edge {
    int from = 0;
    int to = 0;
    int64_t w = 0;

    friend std::istream &operator>>(std::istream &is, Edge &edge) {
        is >> edge.from >> edge.to >> edge.w;
        return is;
    }
};

int main() {
    size_t n = 0, m = 0;
    std::cin >> n >> m;
    int start = 0;
    std::cin >> start;
    std::vector<Edge> edges(m);
    for (size_t i = 0; i < m; ++i) {
        std::cin >> edges[i];
    }
    const int64_t inf = (1LL << 63) - 1;
    std::vector<int64_t> dist(n + 1, inf);
    dist[start] = 0;
    std::set<int> ans;
    for (int k = 1; k <= n; ++k) {
        for (size_t i = 0; i < m; ++i) {
            auto [from, to, w] = edges[i];
            if (dist[from] != inf && dist[to] > dist[from] + w) {
                dist[to] = dist[from] + w;
                if (k == n) {
                    ans.insert(from);
                    ans.insert(to);
                }
            }
        }
    }
    std::vector<std::vector<int> > gr(n + 1);
    for (auto edge : edges) {
        gr[edge.from].emplace_back(edge.to);
    }
    std::vector<int> used = std::vector<int> (n + 1, false);
    std::function<void(int)> dfs= [&](int v) {
        used[v] = true;
        for (auto to : gr[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
    };
    for (auto v : ans) {
        dfs(v);
    }
    for (size_t i = 1; i < dist.size(); ++i) {
        if (used[i]) {
            std::cout << '-' << '\n';
        } else if (dist[i] == inf) {
            std::cout << '*' << '\n';
        } else {
            std::cout << dist[i] << '\n';
        }
    }
    return 0;
}