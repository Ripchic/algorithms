n = int(input())
data = list(map(int, input().split()))
if sum(data) % 2 != 0:
    print("NO")
else:
    r = 1
    for i in data:
        r = r | (r << i)
    res = bin(r)[2:]
    if res[len(res) // 2] == '1':
        print("YES")
    else:
        print("NO")