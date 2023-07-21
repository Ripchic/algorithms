# f = open("input.txt") # stack
# data = []
#
# while 1:
#     a = (f.readline().strip().split())
#     if len(a) != 0:
#         if a[0] == "ADD":
#             data.append(int(a[1]))
#         elif a[0] == "EXTRACT":
#             if len(data) != 0:
#                 print(data.pop(data.index(max(data))))
#             else:
#                 print("CANNOT")
#         elif a[0] == "CLEAR":
#             data.clear()
#     else:
#         raise SystemExit


def Up(i):
    if i == 0:
        return
    p = (i - 1) // 2
    if heap[i] > heap[p]:
        heap[i], heap[p] = heap[p], heap[i]
        Up(p)


def Down(i):
    l = 2 * i + 1
    r = 2 * i + 2
    if l >= len(heap):
        return
    if r == len(heap):
        r = l
    max = l
    if heap[l] < heap[r]:
        max = r
    if heap[i] < heap[max]:
        heap[i], heap[max] = heap[max], heap[i]
        Down(max)


def add(v):
    heap.append(v)
    Up(len(heap) - 1)


def extract():
    if len(heap) != 0:
        i = heap[0]
        heap[0] = heap[-1]
        heap.pop()
        Down(0)
        return i
    else:
        return 'CANNOT'


heap = []
f = open("input.txt")
while 1:
    a = f.readline().strip().split()
    if len(a) != 0:
        if a[0] == 'CLEAR':
            heap.clear()
        elif a[0] == 'ADD':
            add(int(a[1]))
        elif a[0] == 'EXTRACT':
            print(extract())
    else:
        f.close()
        break