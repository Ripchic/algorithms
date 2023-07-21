p = '@' + input()
s = '$' + input()
dp = [[0 for _ in range(len(s))] for _ in range(len(p))]
for i in range(1, len(p)):
    for j in range(1, len(s)):
        if p[i] == s[j]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
ans1 = []
ans2 = []
i = len(p) - 1
j = len(s) - 1
while i > 0 and j > 0:
    if s[j] == p[i]:
        ans1.append(i)
        ans2.append(j)
        i -= 1
        j -= 1
    elif dp[i - 1][j] > dp[i][j - 1]:
        i -= 1
    else:
        j -= 1
print(len(ans1))
print(*ans1[::-1])
print(*ans2[::-1])