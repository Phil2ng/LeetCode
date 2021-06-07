# 特殊规则排序
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        def quick_sort(l, r):
            if l >= r:
                return
            i, j = l, r
            while i < j:
                while i < j and s[j]+s[l] >= s[l]+s[j]:
                    j -= 1
                while i < j and s[i]+s[l] <= s[l]+s[i]:
                    i += 1
                s[i], s[j] = s[j], s[i]
            s[i], s[l] = s[l], s[i]
            quick_sort(l, i-1)
            quick_sort(i+1, r)

        s = list(map(str, nums))
        # quick_sort(0, len(s)-1)
        s.sort(key=functools.cmp_to_key(lambda x, y: 1 if x+y > y+x else -1))
        return ''.join(s)
