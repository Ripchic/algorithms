mod = int(1e9 + 9)
def f_pow_spec(a, n):
    if n == 0:
        return 1
    if n % 2 == 0:
        return f_pow_spec(a * a % mod, n // 2)
    else:
        return a * f_pow_spec(a, n - 1) % mod


n = int(input())
for _ in range(n):
    print(f_pow_spec(int(input()), mod - 2))