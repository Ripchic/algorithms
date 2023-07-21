k = int(input())
a = list(map(int, input().split()))
n = int(input())
count = [0 for _ in range(n + 1)]
for m in range(1, n + 1):
    count[m] = 10 ** 9
    for i in a:
        if m >= i and count[m - i] + 1 < count[m]:
            count[m] = count[m - i] + 1
if count[n] != 10 ** 9:
    print(count[n])
    while n > 0:
        for i in a:
            if n - i >= 0 and count[n - i] == count[n] - 1:
                print(i, end=" ")
                n -= i
                break
else:
    print(-1)