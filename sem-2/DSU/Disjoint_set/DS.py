def find(v: int) -> int:
    return color[v]


def union(a: int, b: int) -> None:
    color_a = find(a)
    color_b = find(b)
    if len(elements[color_a]) < len(elements[color_b]):
        union(b, a)
        return
    for i in elements[color_b]:
        color[i] = color_a
    elements[color_a] += elements[color_b]
    elements[color_b] = []


def check(a: int, b: int) -> bool:
    return find(a) == find(b)


with open("input.txt") as f:
    data = f.readlines()
    for line in data:
        line = line.strip().split()
        action = line[0]
        act_data = line[1:]
        if action == "RESET":
            color = [i for i in range(int(act_data[0]))]
            elements = [[i] for i in range(int(act_data[0]))]
            print("RESET DONE")
        elif action == "JOIN":
            if check(int(act_data[0]), int(act_data[1])):
                print(f"ALREADY {int(act_data[0])} {int(act_data[1])}")
            else:
                union(int(act_data[0]), int(act_data[1]))
        elif action == "CHECK":
            if check(int(act_data[0]), int(act_data[1])):
                print("YES")
            else:
                print("NO")