n = int(input())
a = list(map(int, input().split()))
block = 400
s_block = [-10 ** 9] * (len(a) // block + 1)

for i in range(len(a)):
    s_block[i // block] = max(a[i], s_block[i // block])

m = int(input())
for i in range(m):
    l, r = map(int, input().split())
    L = l - 1
    R = r - 1
    ans = a[L]
    while L <= R:
        if L // block == R // block or L % block != 0:
            ans = max(ans, a[L])
            L += 1
        else:
            ans = max(ans, s_block[L // block])
            L += block
    print(ans, end=" ")