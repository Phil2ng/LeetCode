/*
 * 指针遍历
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		int l = 0, r = numbers.size() - 1, sum;
		while (l < r) {
			sum = numbers[l] + numbers[r];
			if (sum == target)
				break;
			if (sum > target)
				--r;
			else ++l;
		}
		return vector<int> {l + 1, r + 1};
	}
};
// @lc code=end

