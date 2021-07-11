/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * 二分查找
 * 
 * [275] H 指数 II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (n - mid <= citations[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        } 
        return n - l;
    }
};
// @lc code=end

