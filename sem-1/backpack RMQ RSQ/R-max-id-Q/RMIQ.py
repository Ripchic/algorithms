n = int(input())
a = [0] + list(map(int, input().split()))
block = int(n ** 0.5)
s_block = [0 for _ in range(n // block + 1)]
for i in range(n):
    if a[s_block[i // block]] < a[i] or i % block == 0:
        s_block[i // block] = i
for _ in range(int(input())):
    L, R = map(int, input().split())
    max = K = L
    while K <= R:
        if K // block == R // block or K % block != 0:
            if a[K] > a[max]:
                max = K
            K += 1
        else:
            if a[s_block[K // block]] > a[max]:
                max = s_block[K // block]
            K += block
    print(max, end=" ")