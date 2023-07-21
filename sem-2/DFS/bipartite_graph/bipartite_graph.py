import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n, m = map(int, f.readline().split())
    anti_edges = [tuple(map(int, line.split())) for line in f.readlines()]
anti_adj = [[] for _ in range(n)]
for i in range(m):
    anti_adj[anti_edges[i][0] - 1].append(anti_edges[i][1] - 1)
    anti_adj[anti_edges[i][1] - 1].append(anti_edges[i][0] - 1)
visited = [0 for _ in range(n)]


def dfs(v, color):
    visited[v] = color
    for to in anti_adj[v]:
        if not visited[to]:
            dfs(to, color * -1)
        elif visited[to] == color:
            print("NO")
            exit()


for i in range(n):
    if not visited[i]:
        dfs(i, 1)
print("YES")