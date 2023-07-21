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


def dfs(v, parent):
    visited[v] = True
    for to in matrix[v]:
        if not visited[to]:
            if dfs(to, v):
                return True
        elif to != parent:
            return True
    return False


cycle = dfs(0, -1)
if not cycle and n - m == 1:
    print("YES")
else:
    print("NO")