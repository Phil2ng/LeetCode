/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> dict;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto pos = dict.find(target - nums[i]);
            if (pos == dict.end())
            {
                dict[nums[i]] = i;
            }
            else
            {
                ans.push_back(i);
                ans.push_back(pos->second);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

