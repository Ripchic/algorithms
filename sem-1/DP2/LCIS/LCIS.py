n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
dp = [0 for _ in range(m)]
for i in range(n):
    cur = 0
    for j in range(m):
        if a[i] == b[j]:
            if dp[j] < cur + 1:
                dp[j] = cur + 1
        if a[i] > b[j]:
            if cur < dp[j]:
                cur = dp[j]
print(max(dp))