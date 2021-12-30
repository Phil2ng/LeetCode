/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> mp = map<int, int>();
        for (auto &&x : hand)
        {
            mp[x]++;
        }
        while (!mp.empty())
        {
            map<int, int>::iterator it = mp.begin();
            int t = it->first;
            for (int i = t; i < t + groupSize; i++)
            {
                mp[i]--;
                if (mp[i] == 0)
                    mp.erase(i);
                else if (mp[i] < 0)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

