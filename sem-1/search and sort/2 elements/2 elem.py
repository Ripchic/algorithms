a1 = int(input())
a = list(map(int, input().split()))
b1 = int(input())
b = list(map(int, input().split()))

dlt = 1e9
a_n = 0
b_n = 0
flag = 1
amin = a[0]
amax = a[-1]
bmin = b[0]
bmax = b[-1]

if amax < bmin:
    print(amax, bmin)
    flag = 0

elif amin > bmax:
    print(amin, bmax)
    flag = 0

if flag:
    res = []

    for i in a:
        l = 0
        r = b1 - 1
        while r - l > 1:
            m = (r + l) // 2
            if b[m] < i:
                l = m
            else:
                r = m
        if i - b[l] <= b[r] - i:
            res.append(b[l])
        else:
            res.append(b[r])

    semi = list(zip(a, res))
    dlt = 1e9
    for i in range(len(semi)):
        c = abs(semi[i][0] - semi[i][1])
        if c < dlt:
            dlt = c
            ans = [semi[i][0], semi[i][1]]
            if dlt == 0:
                break
    print(*ans)