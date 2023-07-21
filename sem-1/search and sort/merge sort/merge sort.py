a1 = int(input())
a = list(map(int, input().split()))


def merge(a, b):
    c = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
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
    return c


def sort_merge(a):
    if len(a) < 2:
        return a
    else:
        c = len(a) // 2
        return merge(sort_merge(a[:c]), sort_merge(a[c:]))


print(*sort_merge(a))