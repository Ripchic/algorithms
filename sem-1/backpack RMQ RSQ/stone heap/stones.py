# n = int(input())
# a = list(map(int, input().split()))
# dif = 1e9
#
#
# def foo(first, second, cnt):
#     global dif
#     if cnt == n:
#         if dif > abs(first - second):
#             dif = abs(first - second)
#
#     else:
#
#         foo(first + a[cnt], second, cnt + 1)
#         foo(first, second + a[cnt], cnt + 1)
#     return dif
#
#
# print(foo(0, 0, 0))

n = int(input())
w = list(map(int, input().split()))
Bag = sum(w)
res = 1e9
ans_cnt = 0
ans_summ = 0


def foo(index, cnt, summ):
    global ans_cnt
    global ans_summ
    global res
    if index == len(w) or summ > Bag:
        res = min(res, abs(summ - (Bag - summ)))
        return
    if summ > ans_summ:
        ans_summ = summ
        ans_cnt = cnt
    elif summ == ans_summ and ans_cnt > cnt:
        ans_cnt = cnt
    foo(index + 1, cnt, summ)
    foo(index + 1, cnt + 1, summ + w[index])


foo(0, 0, 0)
print(res)