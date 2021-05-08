/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int ans = 0, curMax = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            curMax = max(curMax, arr[i]);
            if (curMax == i)
                ++ans;
        }
        return ans;
    }
};
// @lc code=end

