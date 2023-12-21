class Solution:
    def isValid(self, s: str) -> bool:
        openToClose = {
            ']' : '[',
            '}' : '{',
            ')' : '('
        }

        stack = []
        for paren in s:
            if paren in openToClose:
                if stack and stack[-1] == openToClose[paren]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(paren)
        return True if not stack else False