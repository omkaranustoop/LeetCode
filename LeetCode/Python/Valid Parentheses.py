class Solution:
    def isValid(self, s: str) -> bool:
        ss = []
        for c in s:
            if c == '(' or c == '{' or c == '[':
                ss.append(c)
            else:
                if len(ss) == 0:
                    return False
                else:
                    if c == ')':
                        if ss[len(ss)-1] == '(':
                            ss.pop()
                        else:
                            return False
                    elif c == '}':
                        if ss[len(ss)-1] == '{':
                            ss.pop()
                        else:
                            return False
                    else:
                        if ss[len(ss)-1] == '[':
                            ss.pop()
                        else:
                            return False
        if len(ss) != 0:
            return False
        return True