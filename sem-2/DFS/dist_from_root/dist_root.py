import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n = int(f.readline())
    parent_who = [int(line) for line in f.readlines()]
matrix = [[] for _ in range(n)]
for i in range(n - 1):
    matrix[parent_who[i] - 1].append(i + 1)
    matrix[i + 1].append(parent_who[i] - 1)
visited = [0 for _ in range(n)]


def dfs(v, depth):
    global max_depth, max_verticles
    visited[v] = 1
    if depth > max_depth:
        max_depth = depth
        max_verticles = [v]
    elif depth == max_depth:
        max_verticles.append(v)
    for to in matrix[v]:
        if not visited[to]:
            dfs(to, depth + 1)


max_depth = 0
max_verticles = []
dfs(0, 0)

print(max_depth)
print(len(max_verticles))
print(' '.join(str(v + 1) for v in sorted(max_verticles)))