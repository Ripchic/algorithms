n = int(input())
pos = list(map(int, input().split()))
if n == 2:
    print(abs(pos[1] - pos[0]))
else:
    pos.sort()
    len = [0 for _ in range(n - 1)]
    len[0] = pos[1] - pos[0]
    len[1] = pos[2] - pos[0]
    for i in range(2, n - 1):
        len[i] = min(len[i - 2], len[i - 1]) + pos[i + 1] - pos[i]
    print(len[-1])