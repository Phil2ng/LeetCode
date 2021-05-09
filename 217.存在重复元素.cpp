/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> st;
        for (int &num : nums)
            st.insert(num);
        return nums.size() != st.size();
    }
};
// @lc code=end

