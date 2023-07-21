n = int(input())
a = [0] * 10 ** 6
b = [0] * 10 ** 6
c = [0] * 10 ** 6
a[1] = b[1] = c[1] = 1
for i in range(2, n + 1):
    a[i] = b[i - 1] + c[i - 1]
    b[i] = c[i] = a[i - 1] + b[i - 1] + c[i - 1]
print(a[n] + b[n] + c[n])