#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <set>

const int INF = std::numeric_limits<int>::max();
int n;

bool PathCheck(std::vector<std::tuple<int, int, int>> graph[], int start, int destination,
               int width_limit,
               int time_limit) {
    std::set<std::pair<int, int>> q;
    std::vector<int> dist(n, INF);
    dist[start] = 0;
    q.insert({0, start});
    while (!q.empty()) {
        auto [r, cur] = *q.begin();
        q.erase(q.begin());
        for (auto [to, time, weight]: graph[cur]) {
            if (weight >= width_limit && dist[cur] + time < dist[to]) {
                if (dist[to] != INF) {
                    q.erase(q.find({dist[to], to}));
                }
                dist[to] = dist[cur] + time;
                q.insert({dist[to], to});
            }
        }
    }
    if (dist[destination] <= time_limit) {
        return true;
    }
    return false;
}


int
BinSearchGraph(std::vector<std::tuple<int, int, int>> graph[], int start, int destination, int time_limit) {
    int low = 0;
    int high = 1003000000;
    int max_width = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (PathCheck(graph, start, destination, mid, time_limit)) {
            max_width = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return max_width;
}

int main() {
    int m = 0;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, int>> adj[n];
    n = n;
    for (int i = 0; i < m; i++) {
        int u, v, t, w;
        std::cin >> u >> v >> t >> w;
        adj[u - 1].push_back({v - 1, t, w});
        adj[v - 1].push_back({u - 1, t, w});
    }
    int max_weight =
            BinSearchGraph(adj, 0, n - 1, 1440);
    if (max_weight - 3000000 > 0) {
        std::cout << (max_weight - 3000000) / 100;
    } else {
        std::cout << 0;
    }
    return 0;
}