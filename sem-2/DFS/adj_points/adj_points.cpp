#include <iostream>
#include <fstream>
#include <vector>
#include <set>

int n, m;
std::vector<std::vector<int>> g;
std::vector<bool> used;
std::vector<int> tin;
std::vector<int> up;
std::set<int> points;
int timer = 0;

void dfs(int v, int p) {
    used[v] = true;
    timer += 1;
    up[v] = timer;
    tin[v] = timer;
    int cnt = 0;
    for (int to: g[v]) {
        if (used[to]) {
            up[v] = std::min(up[v], tin[to]);
        } else {
            dfs(to, v);
            cnt += 1;
            up[v] = std::min(up[v], up[to]);
            if (tin[v] <= up[to] && p != -1) {
                points.emplace(v + 1);
            }
        }
    }
    if (p == -1 and cnt > 1) {
        points.emplace(v + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream cin("input.txt");
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    used.resize(n, false);
    tin.resize(n, 0);
    up.resize(n, 0);
    dfs(0, -1);
    std::cout << points.size() << '\n';
    for (auto x: points) {
        std::cout << x << '\n';
    }
    return 0;
}