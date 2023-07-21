def isValid(self, s: str) -> bool:
    stack = []
    for next in s:
        if next in ['[', '(', '{']:
            stack.append(next)
        else:
            if not stack:
                return False
            if next == ']' and stack[-1] == '[':
                stack.pop()
            elif next == ')' and stack[-1] == '(':
                stack.pop()
            elif next == '}' and stack[-1] == '{':
                stack.pop()
            else:
                return False
    return not stack