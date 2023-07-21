from collections import deque

with open('input.txt', 'r') as f:
    n, m, start = map(int, f.readline().split())
    edges = [tuple(map(int, line.split())) for line in f.readlines()]
matrix = [[] for _ in range(n)]
for edge in edges:
    matrix[edge[0] - 1].append(edge[1] - 1)
    matrix[edge[1] - 1].append(edge[0] - 1)

queue = deque([start - 1])
visited = [0 for _ in range(n)]
visited[start - 1] = 1
order = [start]
while queue:
    curr = queue.popleft()
    for to in matrix[curr]:
        if not visited[to]:
            queue.append(to)
            visited[to] = 1
            order.append(to + 1)
print(len(order))
print(*order)