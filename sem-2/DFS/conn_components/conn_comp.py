import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n, m = map(int, f.readline().split())
    edges = [tuple(map(int, line.split())) for line in f.readlines()]
matrix = [[] for _ in range(n)]
for edge in edges:
    matrix[edge[0] - 1].append(edge[1] - 1)
    matrix[edge[1] - 1].append(edge[0] - 1)
visited = [False for _ in range(n)]
components = [0 for _ in range(n)]


def dfs(v, component):
    visited[v] = True
    components[v] = component
    for to in matrix[v]:
        if not visited[to]:
            dfs(to, component)


color = 0
for v in range(n):
    if not visited[v]:
        color += 1
        dfs(v, color)

print(color)
print(*components)