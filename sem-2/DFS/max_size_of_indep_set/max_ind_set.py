import sys

sys.setrecursionlimit(100000000)
with open('input.txt', 'r') as f:
    n = int(f.readline())
    parents = [int(line) for line in f.readlines()]
graph = [[] for _ in range(n + 1)]
for i in range(n):
    if parents[i] != 0:
        graph[i + 1].append(parents[i])
        graph[parents[i]].append(i + 1)


def dfs(dp, v, p):
    for to in graph[v]:
        if to != p:
            dfs(dp, to, v)
    for to in graph[v]:
        if to != p:
            dp[v][0] = dp[to][1] + dp[v][0]
            dp[v][1] = dp[v][1] + min(dp[to][1], dp[to][0])


def minSizeVertexCover(n):
    dp = [[0 for _ in range(2)] for __ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][0] = 0
        dp[i][1] = 1
    dfs(dp, 1, -1)
    return (min(dp[1][0], dp[1][1]))


# Дополнение минимального вершинного покрытия является максимальным независимым множеством
print(n - minSizeVertexCover(n))