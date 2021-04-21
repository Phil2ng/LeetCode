/*
 * 相邻两侧大小关系--贪心算法
 * 前后两次遍历，找出最少改变次数
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
		int total1 = 0, total2 = 0, prev = nums[0], n = nums.size();
		for (int i = 1; i < n; ++i) {
			if (nums[i] < prev)
				++total1;
			else
				prev = nums[i];
		}
		prev = nums[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (nums[i] > prev)
				++total2;
			else
				prev = nums[i];
		}
		return min(total1, total2) <= 1;
	}
};
// @lc code=end

