#
# @lc app=leetcode.cn id=1710 lang=python3
#
# [1710] 卡车上的最大单元数
#

# @lc code=start
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda b: b[1], reverse= True) 
        ans = i = 0
        while truckSize > 0 and i < len(boxTypes):
            t = min(truckSize, boxTypes[i][0])
            ans += t * boxTypes[i][1]
            i += 1
            truckSize -= t  
        return ans
# @lc code=end

