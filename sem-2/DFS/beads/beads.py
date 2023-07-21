import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n = int(f.readline())
    edges = [list(map(int, line.split())) for line in f.readlines()]

graph = [[] for _ in range(n)]
for a, b in edges:
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
used = [0 for _ in range(n)]
path = []
ans = []


def dfs(v):
    global ans, path
    used[v] = 1
    path.append(v)
    for to in graph[v]:
        if not used[to]:
            dfs(to)
    if len(path) > len(ans):
        ans = path[:]
    path.pop()


dfs(0)
used = [0 for _ in range(n)]
dfs(ans[-1])
print(len(ans))