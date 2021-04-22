/*
 * 相向指针遍历
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
		long l = 0, r = floor(sqrt(c));
		while (l <= r) {
			if (l * l + r * r == c)
				return true;
			l * l + r * r < c ? ++l : --r;
		}
		return false;
	}
};
// @lc code=end

