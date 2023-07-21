n = int(input())
solo = [0 for _ in range(n)]
duo = [0 for _ in range(n)]
trio = [0 for _ in range(n)]
time = [0 for _ in range(n)]
for i in range(n):
    solo[i], duo[i], trio[i] = map(int, input().split())
time[0] = solo[0]
if n > 1:
    time[1] = min(solo[0] + solo[1], duo[0])
    for i in range(2, n):
        if i - 3 < 0:
            time[i] = min(time[i - 1] + solo[i], time[i - 2] + duo[i - 1], trio[i - 2])
        else:
            time[i] = min(time[i - 1] + solo[i], time[i - 2] + duo[i - 1], time[i - 3] + trio[i - 2])
print(time[-1])