import sys

sys.setrecursionlimit(100000000)
with open('step.in', 'r') as f:
    n, m, start = map(int, f.readline().split())
    edges = [tuple(map(int, line.split())) for line in f.readlines()]
path = []
matrix = [[] for _ in range(n)]
for edge in edges:
    matrix[edge[0] - 1].append(edge[1] - 1)
    matrix[edge[1] - 1].append(edge[0] - 1)
visited = [False for _ in range(n)]


def dfs(v):
    visited[v] = True
    path.append(v + 1)
    for to in matrix[v]:
        if not visited[to]:
            dfs(to)
            path.append(v + 1)


dfs(start - 1)
print(len(path))
print(*path)