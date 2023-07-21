def Up(i):
    if i == 0:
        return
    p = (i - 1) // 2
    if heap[i] < heap[p]:
        heap[i], heap[p] = heap[p], heap[i]
        Up(p)


def Down(i):
    l = 2 * i + 1
    r = 2 * i + 2
    if l >= len(heap):
        return
    if r == len(heap):
        r = l
    min = l
    if heap[l] > heap[r]:
        min = r
    if heap[i] > heap[min]:
        heap[i], heap[min] = heap[min], heap[i]
        Down(min)


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
        print('CANNOT')


heap = []
input()
data = list(map(int, input().split()))
total_cost = 0
# import heapq as hp
# hp.heapify(data)
# while len(data) > 1:
#     a, b = hp.heappop(data), hp.heappop(data)
#     total_cost += (a + b) * 0.05
#     hp.heappush(data, a + b)
# print(f"{total_cost:.2f}")
for i in data:
    add(i)
while len(heap) > 1:
    a, b = extract(), extract()
    total_cost += (a + b) * 0.05
    add(a + b)
print(f"{total_cost:.2f}")