ans = [-1]
def sol(n):
    if n < 0:
        return
    if n == 0:
        print(*ans[1:])
    for i in range(n, 0, -1):
        if i >= ans[-1]:
            ans.append(i)
            sol(n - i)
            ans.pop()
sol(int(input()))