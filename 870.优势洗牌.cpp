/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        unordered_multimap<int, int> mp;
        vector<int> a = A, b = B;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        stack<int> stk;
        for (int j = 0, i = 0; j < b.size();)
        {
            if (i < a.size())
            {
                if (a[i] > b[j])
                {
                    mp.insert({b[j++], a[i++]});
                }
                else
                {
                    stk.push(a[i++]);
                }
            }
            else
            {
                mp.insert({b[j++], stk.top()});
                stk.pop();
            }
        }
        vector<int> ans;
        for (int num : B)
        {
            auto it = mp.find(num);
            ans.push_back(it->second);
            mp.erase(it);
        }
        return ans;
    }
};
// @lc code=end

