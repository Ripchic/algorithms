def find(v: int):
    r = v
    while p[r] != -1:
        r = p[r]
    while p[v] != -1:
        tmp = p[v]
        p[v] = r
        v = tmp
    return r


def union(a: int, b: int):
    p[find(a)] = find(b)


def check(a: int, b: int) -> bool:
    return find(a) == find(b)


edges = []
with open("input.txt") as f:
    n, m = map(int, f.readline().split())
    for _ in range(m):
        u, v, w = map(int, f.readline().split())
        edges.append((w, u, v))
edges.sort()
p = [-1] * n
total_weight = 0
for w, u, v in edges:
    if find(u) != find(v):
        union(u, v)
        total_weight += w

if p.count(-1) > 1:
    print("NON-CONNECTED")
else:
    print(total_weight)