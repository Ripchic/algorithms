n, k = map(int, input().split())
a = [0 for _ in range(n + 1)]
block = int(n ** 0.5)
s_block = [0 for _ in range(len(a) // block + 1)]
for i in range(len(a)):
    s_block[i // block] += a[i]
for _ in range(k):
    data = input().strip().split()
    if data[0] == "A":
        i = int(data[1])
        x = int(data[2])
        s_block[i // block] = s_block[i // block] - a[i] + x
        a[i] = x
    else:
        L = int(data[1])
        R = int(data[2])
        summ = 0
        k = L
        while k <= R:
            if k // block == R // block or k % block != 0:
                summ += a[k]
                k += 1
            else:
                summ += s_block[k // block]
                k += block
        print(summ)