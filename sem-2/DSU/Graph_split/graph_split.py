def find(v: int) -> int:
    return color[v]


def union(a: int, b: int) -> None:
    color_a = find(a)
    color_b = find(b)
    if color_a == color_b:
        return
    if len(elements[color_a]) < len(elements[color_b]):
        union(b, a)
        return
    for i in elements[color_b]:
        color[i] = color_a
    elements[color_a] += elements[color_b]
    elements[color_b] = []


def check(a: int, b: int) -> bool:
    return find(a) == find(b)


ans = []
with open("input.txt") as f:
    data = f.readlines()
    n, m, c = map(int, data[0].strip().split())
    color = [i for i in range(n)]
    elements = [[i] for i in range(n)]
    for line in data[-1:m:-1]:
        line = line.strip().split()
        action = line[0]
        act_data = line[1:]
        if action == "ask":
            if check(int(act_data[0]) - 1, int(act_data[1]) - 1):
                ans.append("YES")
            else:
                ans.append("NO")
        elif action == "cut":
            union(int(act_data[0]) - 1, int(act_data[1]) - 1)
print(*reversed(ans), sep="\n")