"""
Stack
Problem: Valid Parentheses

Example:

Input: "()[]{}"
Output: True
"""


def is_valid_parentheses(s: str) -> bool:
    if not isinstance(s, str):
        raise ValueError("Input must be a string")

    if len(s) % 2 != 0:
        return False

    stack = []

    pairs = {")": "(", "]": "[", "}": "{"}

    for c in s:
        if c in pairs:
            if not stack or stack.pop() != pairs[c]:
                return False
        else:
            stack.append(c)

    return not stack


print(is_valid_parentheses("()[](({}))"))
