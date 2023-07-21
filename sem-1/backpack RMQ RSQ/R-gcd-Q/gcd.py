def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

n = int(input())
a = list(map(int, input().split()))
block = int(n ** 0.5)
# print(block)
s_block = [0 for _ in range(len(a) // block + 1)]
for i in range(len(a)):
    # if i % block == 0:
    s_block[i // block] = gcd(a[i], s_block[i // block])
# print(s_block)
k = int(input())

for _ in range(k):
    L, R = map(int, input().split())
    L -= 1
    R -= 1
    K = L
    ans = a[K]
    while K <= R:
        if K // block == R // block or K % block != 0:
            ans = gcd(ans, a[K])
            K += 1
        else:
            ans = gcd(ans, s_block[K // block])
            K += block
    print(ans, end=" ")