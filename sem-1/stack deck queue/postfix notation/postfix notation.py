stack = []
actions = list(input().strip().split())
for i in range(len(actions)):
    try:
        stack.append(int(actions[i]))
    except ValueError:
        if actions[i] == "+":
            temp = stack[-2] + stack[-1]
            stack.pop()
            stack.pop()
            stack.append(temp)
        if actions[i] == "-":
            temp = stack[-2] - stack[-1]
            stack.pop()
            stack.pop()
            stack.append(temp)
        if actions[i] == "*":
            temp = stack[-2] * stack[-1]
            stack.pop()
            stack.pop()
            stack.append(temp)
print(*stack)