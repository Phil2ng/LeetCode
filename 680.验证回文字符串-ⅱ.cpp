/*
 * 相向指针遍历，贪心思想
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool checkPalindrome(const string s, int l, int r) {
		while (l < r) {
			if (s[l++] != s[r--])
				return false;
		}
		return true;
	}

	bool validPalindrome(string s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l] == s[r]) {
				++l;
				--r;
			} else {
				return checkPalindrome(s, l, r - 1) || checkPalindrome(s, l + 1, r);
			}
		}
		return true;
	}

};
// @lc code=end

