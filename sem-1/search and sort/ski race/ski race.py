cnt = 0

def merge(a, b):
    global cnt
    c = []
    i, j = 0, 0
    while i < len(a) or j < len(b):
        if i == len(a):
            c += [b[j]]
            j += 1
        elif j == len(b):
            c += [a[i]]
            i += 1
        elif a[i] <= b[j]:
            c += [a[i]]
            i += 1
        elif a[i] > b[j]:
            c += [b[j]]
            j += 1
            cnt += len(a) - i
    return c


def sort_merge(a):
    if len(a) < 2:
        return a
    else:
        c = len(a) // 2
        return merge(sort_merge(a[:c]), sort_merge(a[c:]))


b, c = map(int, input().split())
a = list(map(int, input().split()))
all = list(enumerate(a, 1))
time = [[0] for i in range(b)]
for pos, vel in all:
    time[pos - 1] = c * vel + pos - 1
a = sort_merge(time)
print(cnt)