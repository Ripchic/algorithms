n, t = map(int, input().split())
head = [i for i in range(1, n + 1)]
used = [0] * n
cnt = 0

def gen(tail):
    global cnt
    if len(tail) == n:
        print(*tail)
        cnt += 1
        if cnt == t:
            raise SystemExit
    for i in range(n):
        if used[i] < 1:
            used[i] += 1
            if len(tail) != i:
                gen(tail + [head[i]])
            used[i] = 0

gen([])