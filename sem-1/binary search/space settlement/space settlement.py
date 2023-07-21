def binary1(n, a, b, w, h):
    l, r = -1, 10 ** 20
    while r - l > 1:
        d = (l + r) // 2
        key = (h // (a + 2 * d)) * (w // (b + 2 * d))
        if key >= n:
            l = d
        else:
            r = d
    if l == -1:
        return 0
    return l

def binary2(n, a, b, w, h):
    l, r = -1, 10 ** 20
    while r - l > 1:
        d = (l + r) // 2
        key = (w // (a + 2 * d)) * (h // (b + 2 * d))
        if key >= n:
            l = d
        else:
            r = d
    if l == -1:
        return 0
    return l

with open("input.txt") as f:
    n, a, b, w, h = map(int, f.readline().split())
print(max(binary1(n, a, b, w, h), binary2(n, a, b, w, h)))