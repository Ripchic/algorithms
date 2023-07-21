import bisect

n, a1, k, b, m = map(int, input().split())
a = [a1]
for i in range(1, n):
    a.append((k * a[i - 1] + b) % m)

dp = [10 ** 9 for _ in range(n)]
dp[0] = -10 ** 9
len = 0
for i in range(n):
    j = bisect.bisect(dp, a[i])
    if a[i] < dp[j] and dp[j - 1] < a[i]:
        dp[j] = a[i]
        len = max(len, j)
print(len)