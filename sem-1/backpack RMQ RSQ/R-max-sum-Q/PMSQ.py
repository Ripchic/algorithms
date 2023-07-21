n = int(input())
a = [0] + list(map(int, input().split()))
p = [0 for _ in range(n + 1)]
m = [0 for _ in range(n + 1)]
ans = -1e9
l, r, t_i = 1, n + 1, 1
for i in range(1, n + 1):
    p[i] = p[i - 1] + a[i]
    if m[i - 1] > p[i - 1]:
        m[i] = p[i - 1]
        t_i = i
    else:
        m[i] = m[i - 1]
    if ans < p[i] - m[i]:
        ans = p[i] - m[i]
        l, r = t_i, i
if n == 1 or a[1] == 0 and l > r:
    print(1, 1, ans)
else:
    print(l, r, ans)