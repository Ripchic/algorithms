#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

int n, m;
std::vector<std::vector<int>> g;
std::vector<bool> used;
std::vector<int> tin;
std::vector<int> up;
std::vector<std::pair<int, int>> bridges;
int timer = 0;

void dfs(int v, int p) {
    used[v] = true;
    timer += 1;
    up[v] = timer;
    tin[v] = timer;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        if (used[to]) {
            up[v] = std::min(up[v], tin[to]);
        } else {
            dfs(to, v);
            up[v] = std::min(up[to], up[v]);
            if (tin[v] < up[to]) {
                bridges.emplace_back(v + 1, to + 1);
                bridges.emplace_back(to + 1, v + 1);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream cin("input.txt");
    std::vector<std::pair<int, int>> indata;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;
        indata.emplace_back(a, b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    used.resize(n, false);
    tin.resize(n, 0);
    up.resize(n, 0);
    dfs(0, 0);
    std::vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (std::find(bridges.begin(), bridges.end(), indata[i]) != bridges.end()) {
            ans.push_back(i + 1);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto v: ans) {
        std::cout << v << '\n';
    }
    return 0;
}