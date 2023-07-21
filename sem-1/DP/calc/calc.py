n = int(input())
dp = [0 for _ in range(n + 1)]
p = [-1 for _ in range(n + 1)]
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + 1
    p[i] = i - 1
    if i % 2 == 0 and dp[i // 2] + 1 < dp[i]:
        dp[i] = dp[i // 2] + 1
        p[i] = i // 2
    if i % 3 == 0 and dp[i // 3] + 1 < dp[i]:
        dp[i] = dp[i // 3] + 1
        p[i] = i // 3
ans = []
while n != -1:
    ans.append(n)
    n = p[n]
print(len(ans) - 1)
print(*ans[::-1])