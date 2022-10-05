#
# @lc app=leetcode.cn id=811 lang=python3
#
# [811] 子域名访问计数
#

# @lc code=start
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        cnt = defaultdict(int)
        for s in cpdomains:
            sb, sa = s.split(' ')
            t = int(sb)
            ls = sa.split('.')
            for i in range(len(ls)):
                ss = '.'.join(ls[i:])
                cnt[ss] += t
        ans = []
        for k,v in cnt.items():
            ans.append(str(v) + ' ' + k)
        return ans
# @lc code=end

