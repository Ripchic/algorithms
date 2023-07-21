#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <limits>

const int64_t inf = std::numeric_limits<int64_t>::max();

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
    std::vector<Edge> edges(m);
    for (size_t i = 0; i < m; ++i) {
        std::cin >> edges[i];
    }

    std::vector<int64_t> dist(n + 1, -inf);
    dist[1] = 0;
    std::set<int> ans;
    for (int k = 1; k <= n; ++k) {
        for (size_t i = 0; i < m; ++i) {
            auto [from, to, w] = edges[i];
            if (dist[from] != -inf && dist[to] < dist[from] + w) {
                dist[to] = dist[from] + w;
                if (k == n) {
                    ans.insert(from);
                    ans.insert(to);
                }
            }
        }
    }

    std::vector<std::vector<int> > gr(n + 1);
    for (auto edge: edges) {
        gr[edge.from].emplace_back(edge.to);
    }
    std::vector<int> used = std::vector<int>(n + 1, false);

    std::function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (auto to: gr[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
    };
    for (auto v: ans) {
        dfs(v);
    }

    if (used[n]) {
        std::cout << ":)";
    } else if (dist[n] == -inf) {
        std::cout << ":(";
    } else {
        std::cout << dist[n];
    }

    return 0;
}