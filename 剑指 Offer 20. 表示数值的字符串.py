# 分类讨论

class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if s.count('e') == 0 and s.count('E') == 0:
            return self.isFloat(s) or self.isInt(s)
        elif s.count('e') == 1:
            p = s.split('e')
            return (self.isFloat(p[0]) or self.isInt(p[0])) and self.isInt(p[1])
        elif s.count('E') == 1:
            p = s.split('E')
            return (self.isFloat(p[0]) or self.isInt(p[0])) and self.isInt(p[1])
        else:
            return False

    def isInt(self, s):
        if len(s) == 0:
            return False
        if len(s) == 1:
            return s.isdigit()
        if s.isdigit() or (s[0] == '+' or s[0] == '-') and s[1:].isdigit():
            return True
        else:
            return False

    def isFloat(self, s):
        q = s.split('.')
        if len(q) != 2:
            return False
        if len(q[0]) > 0 and (s[0] == '+' or s[0] == '-'):
            q[0] = q[0][1:]
        if (q[0].isdigit() and len(q[1]) == 0):
            return True
        if (q[0].isdigit() and q[1].isdigit()):
            return True
        if (len(q[0]) == 0 and q[1].isdigit()):
            return True
        return False
