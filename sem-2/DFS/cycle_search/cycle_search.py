import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n, m = map(int, f.readline().split())
    edges = [list(map(int, line.split())) for line in f.readlines()]

graph = [[] for _ in range(n)]
for a, b in edges:
    graph[a - 1].append(b - 1)
used = [0 for _ in range(n)]
path = []
status = False
cycle_st = 0
cycle_end = 0


def dfs(v):
    global path, status, cycle_st, cycle_end
    used[v] = 1
    path.append(v)
    for to in graph[v]:
        if status:
            return
        elif not used[to]:
            dfs(to)
        elif used[to] == 1:
                status = True
                cycle_st = to
                cycle_end = v
    if status:
        return
    used[v] = 2
    path.pop()


for v in range(n):
    if not used[v]:
        dfs(v)
if status:
    print("YES")
    print(*[i + 1 for i in path[path.index(cycle_st):path.index(cycle_end) + 1:]])
else:
    print("NO")