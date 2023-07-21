def find(v: int):
    r = v
    while p[r] != -1:
        r = p[r]
    while p[v] != -1:
        tmp = p[v]
        p[v] = r
        v = tmp
    return r


def union(a: int, b: int, w: int):
    pa, pb = find(a), find(b)
    if pa != pb:
        p[pa] = pb
        weights[pb] += weights[pa] + w
    else:
        weights[pb] += w


with open("input.txt") as f:
    n, m = map(int, f.readline().split())
    p = [-1] * (n + 1)
    weights = [0] * (n + 1)
    for _ in range(m):
        data = list(map(int, f.readline().split()))
        if data[0] == 1:
            x, y, w = data[1], data[2], data[3]
            union(x, y, w)
        else:
            x = data[1]
            print(weights[find(x)])