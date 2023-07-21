#include <iostream>
#include <vector>
#include <limits>

const int64_t INF = std::numeric_limits<int64_t>::max();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n = 0;
    std::cin >> n;

    std::vector<int64_t> dist(n + 1, INF);
    dist[1] = 0;

    for (size_t i = 1; i < n; ++i)
        for (size_t j = i + 1; j <= n; ++j) {
            int64_t w = (179 * i + 719 * j) % 1000 - 500;
            if (dist[i] < INF && dist[i] + w < dist[j]) {
                dist[j] = dist[i] + w;
            }
        }

    std::cout << dist[n];
    return 0;
}