#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

std::vector<std::string> p;

int GetID(std::string name) {
    for (size_t i = 0; i < p.size(); ++i) {
        if (p[i] == name) {
            return i;
        }
    }
    p.push_back(name);
    return p.size() - 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> gr(1001);
    std::string from, arrow, to;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> from >> arrow >> to;
        gr[GetID(from)].push_back({GetID(to), 1});
    }
    std::string s, f;
    std::cin >> s >> f;
    std::set<std::pair<int, int>> q;
    const int inf = 1 << 30;
    std::vector<int> dist(1001, inf);
    dist[GetID(s)] = 0;
    q.insert({0, GetID(s)});
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
    if (dist[GetID(f)] == inf) {
        std::cout << -1;
    } else {
        std::cout << dist[GetID(f)];
    }
    return 0;
}