/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        vector<string> ans;
        if (tickets.empty())
            return ans;
        unordered_map<string, multiset<string>> hash;
        for (auto &t : tickets)
        {
            hash[t[0]].insert(t[1]);
        }
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty())
        {
            string from = stk.top();
            if (!hash[from].empty())
            {
                stk.push(*hash[from].begin());
                hash[from].erase(hash[from].begin());
            }
            else
            {
                ans.push_back(from);
                stk.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

