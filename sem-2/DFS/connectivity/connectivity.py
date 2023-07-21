import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n, m = map(int, f.readline().split())
    edges = [tuple(map(int, line.split())) for line in f.readlines()]
matrix = [[0 for j in range(n)] for i in range(n)]
for edge in edges:
    matrix[edge[0] - 1][edge[1] - 1] += 1
    matrix[edge[1] - 1][edge[0] - 1] += 1
visited = [False for j in range(n)]


def dfs(v):
    visited[v] = True
    for to in range(n):
        if matrix[v][to] and not visited[to]:
            dfs(to)


dfs(0)
if all(visited):
    print("YES")
else:
    print("NO")