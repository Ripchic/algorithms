none = int(input())
a = list(map(int, input().split()))
dp = [1] * len(a)
p = [-1] * len(a)

for i in range(1, len(a)):
    for j in range(i - 1, -1, -1):
        if a[i] > a[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1
            p[i] = j
v = dp.index(max(dp))
ans = []
while v != -1:
    ans.append(a[v])
    v = p[v]
print(len(ans[::-1]))