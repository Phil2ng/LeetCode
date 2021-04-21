/*
 * 分配问题--贪心算法
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
	bool canPlaceFlowers(vector<int> &flowerbed, int n) {
		int size = flowerbed.size();
		if (size == 1 && flowerbed[0] == 0 || size == 2 && flowerbed[0] == 0 && flowerbed[1] == 0)
			--n;
		else if (size > 2) {
			if ((flowerbed[0] | flowerbed[1]) == 0) {
				--n;
				flowerbed[0] = 1;
			}
			for (int i = 1; i < size - 1; ++i) {
				if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
					--n;
					flowerbed[i] = 1;
				}
			}
			if ((flowerbed[size - 2] | flowerbed[size - 1]) == 0) {
				--n;
				flowerbed[size - 1] = 1;
			}
		}
		if (n <= 0)
			return true;
		else
			return false;
	}
};
// @lc code=end

