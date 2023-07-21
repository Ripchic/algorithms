nonne, Bag = map(int, input().split())
weight = [0] + list(map(int, input().split()))
cost = [0] + list(map(int, input().split()))

dp = [[-1] * (Bag + 1) for i in range(len(weight))]
dp[0][0] = 0
for i in range(1, len(weight)):
    for j in range(Bag + 1):
        dp[i][j] = dp[i - 1][j]
        wi = weight[i]
        ci = cost[i]
        if j - wi < 0 or dp[i - 1][j - wi] == -1:
            continue
        if dp[i][j] < dp[i - 1][j - wi] + ci:
            dp[i][j] = dp[i - 1][j - wi] + ci

# for i in range(len(dp)):
#     print(*dp[i], sep='\t')

mx = max(dp[-1])
print(mx)