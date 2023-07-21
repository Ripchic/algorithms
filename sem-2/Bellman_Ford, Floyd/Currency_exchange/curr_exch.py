N, M, S, V = map(float, input().split())
S = int(S)

graph = [[] for _ in range(int(N))]
for _ in range(int(M)):
    A, B, RAB, CAB, RBA, CBA = map(float, input().split())
    A = int(A) - 1
    B = int(B) - 1
    graph[A].append((B, RAB, CAB))
    graph[B].append((A, RBA, CBA))

dist = [float('-inf') for _ in range(int(N))]
dist[S - 1] = V

for _ in range(int(N) - 1):
    for u in range(int(N)):
        for v, rate, commission in graph[u]:
            if dist[u] != float('-inf') and (dist[u] - commission) * rate > dist[v]:
                dist[v] = (dist[u] - commission) * rate

for u in range(int(N)):
    for v, rate, commission in graph[u]:
        if dist[u] != float('-inf') and (dist[u] - commission) * rate > dist[v]:
            print("YES")
            raise SystemExit

if dist[S - 1] > V:
    print('YES')
else:
    print('NO')