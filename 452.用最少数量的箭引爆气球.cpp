/*
 * 区间问题--贪心算法
 * 计数右边界小且不相交的区间
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
		if (points.empty())
			return 0;
		sort(points.begin(), points.end(), [](const vector<int> a, const vector<int> b) {
			return a[1] < b[1];
		});
		int total = 1, prev = points[0][1], n = points.size();
		for (const vector<int> &bolloon : points) {
			if (bolloon[0] > prev) {
				++total;
				prev = bolloon[1];
			}
		}
		return total;
	}
};
// @lc code=end

