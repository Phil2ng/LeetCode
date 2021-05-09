/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        int ans;
        for (int num : nums)
        {
            if (st.find(num) == st.end())
                st.insert(num);
            else
            {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

