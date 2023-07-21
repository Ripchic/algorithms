a1 = int(input())
a = list(map(int, input().split()))
b1 = int(input())
b = list(map(int, input().split()))

c = []
i, j = 0, 0
while i < a1 and j < b1:
    if a[i] < b[j]:
        c.append(a[i])
        i += 1
    else:
        c.append(b[j])
        j += 1
if i < len(a):
    c += a[i:]
if j < len(b):
    c += b[j:]
print(*c)