/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>> &points)
    {
        unordered_map<string, int> hash;
        int ans = 1;
        for (int i = 0; i < points.size(); ++i)
        {
            int same = 1, same_x = 1;
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[i][0] == points[j][0])
                {
                    ++same_x;
                    if (points[i][1] == points[j][1])
                        ++same;
                }
                else
                {
                    int dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
                    string str = to_string(dx / __gcd(dx, dy)) + "_" + to_string(dy / __gcd(dx, dy));
                    ++hash[str];
                }
            }
            ans = max(ans, same_x);
            for (auto item : hash)
            {
                ans = max(ans, same + item.second);
            }
            hash.clear();
        }
        return ans;
    }
};
// @lc code=end

