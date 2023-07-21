n = int(input())
a = list(map(int, input().split()))

for k in range(32):
    q0 = []
    q1 = []
    for x in a:
        if (x & (1 << k)) == 0:
            q0.append(x)
        else:
            q1.append(x)
    a = list(q0) + list(q1)
print(*a)