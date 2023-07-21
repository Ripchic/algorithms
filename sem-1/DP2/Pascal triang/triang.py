n = int(input())
dp = [[1] * n for _ in range(n)]
for i in range(1, n):
    for j in range(1, n):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
for i in range(n):
    m = 0
    for j in range(i + 1):
        print(dp[i][m], end=" ")
        m += 1
        i -= 1
    print()