n = int(input())
a = list(map(int, input().split()))
block = 400
s_block = [-10 ** 9] * (len(a) // block + 1)

for i in range(len(a)):
    s_block[i // block] = max(a[i], s_block[i // block])

m = int(input())
for i in range(m):
    data = input().split()
    if data[0] == "s":
        L = int(data[1]) - 1
        R = int(data[2]) - 1
        ans = a[L]
        while L <= R:
            if L // block == R // block or L % block != 0:
                ans = max(ans, a[L])
                L += 1
            else:
                ans = max(ans, s_block[L // block])
                L += block
        print(ans, end=" ")
    else:
        ind = int(data[1]) - 1
        val = int(data[2])
        a[ind] = val
        L = ind // block * block
        R = min(L + block, len(a))
        s_block[ind // block] = a[L]
        for i in range(L, R):
            s_block[ind // block] = max(s_block[ind // block], a[i])