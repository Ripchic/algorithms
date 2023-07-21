Bag, none = map(int, input().split())
w = [0] + list(map(int, input().split()))
dp = [[-1] * (Bag + 1) for i in range(len(w))]
dp[0][0] = 0
for i in range(1, len(w)):
    for j in range(Bag + 1):
        dp[i][j] = dp[i - 1][j]
        wi = w[i]
        if j - wi < 0 or dp[i - 1][j - wi] == -1:
            continue
        if dp[i][j] > dp[i - 1][j - wi] + 1 or dp[i][j] == -1:
            dp[i][j] = dp[i - 1][j - wi] + 1
ans = 0
for i in range(len(dp[0])):
    if dp[len(dp) - 1][i] != -1:
        ans = i
print(ans)