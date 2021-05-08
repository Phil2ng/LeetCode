/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution
{
public:
    // 使用multiset
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        multiset<pair<int, int>> points;
        for (vector<int> b : buildings)
        {
            points.insert(make_pair(b[0], -b[2]));
            points.insert(make_pair(b[1], b[2]));
        }
        multiset<int> heights;
        int prevh = 0;
        for (auto &[x, h] : points)
        {
            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));

            int maxHeight = *heights.rbegin();
            if (maxHeight != prevh)
            {
                res.push_back({x, maxHeight});
                prevh = maxHeight;
            }
        }
        return res;
    }
    // 使用priority_queue
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> max_heap;
        int i = 0, len = buildings.size(), cur_x, cur_h, prev_h = 0;
        while (i < len || !max_heap.empty())
        {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second)
            {
                cur_x = buildings[i][0];
                while (i < len && buildings[i][0] == cur_x)
                {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            }
            else
            {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && max_heap.top().second <= cur_x)
                    max_heap.pop();
            }

            cur_h = max_heap.empty() ? 0 : max_heap.top().first;
            if (cur_h != prev_h)
            {
                res.emplace_back(vector<int>{cur_x, cur_h});
                prev_h = cur_h;
            }
        }
        return res;
    }
};
// @lc code=end
