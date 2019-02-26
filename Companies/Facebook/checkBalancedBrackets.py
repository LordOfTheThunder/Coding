# Company: Facebook
# Question: Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
# Example:
"""
For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
"""
# Solution: use stack to trace last type of open braces

class Stack:
    def __init__(self):
        self.stack = []
    def push(self, lm):
        self.stack.append(lm)
    def pop(self):
        if len(self.stack) == 0:
            return "empty"
        return self.stack.pop()
    def is_empty(self):
        return len(self.stack) == 0

def checkBalancedBrackets(brackets):
    def match(opener, closer):
        return (opener == '[' and closer == ']') or (opener == '{' and closer == '}') or (opener == '(' and closer == ')')
    open_stack = Stack()
    for char in brackets:
        if char in ['[', '{', '(']:
            open_stack.push(char)
        if char in [']', '}', ')']:
            if open_stack.is_empty():
                return False
            if not match(open_stack.pop(), char):
                return False
    return open_stack.is_empty()

if __name__ == "__main__":
    assert(checkBalancedBrackets('([])[]({})') is True)
    assert(checkBalancedBrackets('([)]') is False)
    assert(checkBalancedBrackets('((()') is False)
