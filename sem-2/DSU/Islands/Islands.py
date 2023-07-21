def find(v: int) -> int:
    r = v
    while p[r] != -1:
        r = p[r]
    while p[v] != -1:
        tmp = p[v]
        p[v] = r
        v = tmp
    return r


def union(a: int, b: int) -> None:
    p[find(a)] = find(b)


with open("input.txt") as f:
    n, m = map(int, f.readline().split())

    p = [-1] * (n + 1)

    cnt = 0
    for i in range(m):
        a, b = map(int, f.readline().split())
        if find(a) != find(b):
            union(a, b)
            cnt += 1
        if cnt == n - 1:
            print(i + 1)
            break