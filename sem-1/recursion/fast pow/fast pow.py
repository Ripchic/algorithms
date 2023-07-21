def f_pow(a, n):
    if n == 0:
        return 1
    if n % 2 == 0:
        return f_pow(a * a, n // 2)
    else:
        return a * f_pow(a, n - 1)


a = float(input())
n = float(input())
print(f_pow(a, n))