import heapq

with open('island.in', 'r') as f:
    n, m = map(int, f.readline().split())
    kings_cities = list(map(int, f.readline().split()))
    edges = [list(map(int, line.split())) for line in f.readlines()]
for i in range(m):
    if kings_cities[edges[i][0] - 1] == kings_cities[edges[i][1] - 1]:
        edges[i].append(0)
    else:
        edges[i].append(1)
graph = [[] for _ in range(n)]
for a, b, w in edges:
    graph[a - 1].append((b - 1, w))
    graph[b - 1].append((a - 1, w))

dist = [float('inf') for _ in range(n)]
dist[0] = 0
prev = [-1 for _ in range(n)]

q = [(0, 0)]

while q:
    d, u = heapq.heappop(q)
    if d > dist[u]:
        continue
    for v, w in graph[u]:
        if dist[u] + w < dist[v]:
            dist[v] = dist[u] + w
            prev[v] = u
            heapq.heappush(q, (dist[v], v))

if dist[-1] == float('inf'):
    print("impossible")
else:
    path = [n]
    u = -1
    while prev[u] != -1:
        path.append(prev[u] + 1)
        u = prev[u]
    print(dist[n - 1], len(path))
    print(*reversed(path))