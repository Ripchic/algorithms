num = int(input())

f = [0 for _ in range(num + 1)]
f[0] = f[1] = 1
for i in range(2, num + 1):
    if i % 2 == 0:
        f[i] = f[i // 2] + 1
    else:
        f[i] = f[i // 2 + 1] + f[i // 2] + 1
print(f[num])