#include <iostream>
#include <vector>
#include <limits>


const int INF = std::numeric_limits<int>::max();

struct Edge {
    int from, to, weight;
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    std::vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (const Edge &edge: edges) {
            if (dist[edge.from] != INF && dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }
    for (const auto &value: dist) {
        if (value != INF)
            std::cout << value << ' ';
        else
            std::cout << 30000 << ' ';
    }
    return 0;
}