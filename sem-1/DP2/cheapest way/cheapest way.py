n, m = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(n)]

dp = [[0 for _ in range(m)] for _ in range(n)]
str_check = 1
for i in range(n):
    f_elem = 1
    for j in range(m):
        if str_check:
            dp[i][j] = p[i][j] + dp[i][j - 1]
        elif f_elem:
            dp[i][j] = p[i][j] + dp[i - 1][j]
            f_elem = 0
        else:
            dp[i][j] = p[i][j] + min(dp[i - 1][j], dp[i][j - 1])
    str_check = 0
print(dp[-1][-1])