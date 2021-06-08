# 字符串
class Solution:
    def strToInt(self, str: str) -> int:
        a = list(str.strip())
        ans = 0
        flag = True
        if a and a[0] == '-':
            flag = False
            a.pop(0)
        elif a and a[0] == '+':
            flag = True
            a.pop(0)

        while a and a[0] in "0123456789":
            t = int(a.pop(0))
            ans = ans*10+t

        ans = ans if flag else -ans
        ans = ans if ans >= -2**31 else -2**31
        ans = ans if ans < 2**31 else 2**31-1
        return ans
