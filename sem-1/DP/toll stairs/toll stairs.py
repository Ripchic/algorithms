n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(a[-1])
elif n == 2:
    print(a[-1])
else:
    for i in range(2, n):
        a[i] += min(a[i - 2], a[i - 1])
    print(a[-1])