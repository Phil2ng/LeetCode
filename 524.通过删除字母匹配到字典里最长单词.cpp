/*
 * 双指针遍历
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
		int m = s.size();
		string ans = "";
		for (string dict : dictionary) {
			int i = 0, j = 0, n = dict.size();
			if (ans.size() > n)
				continue;
			while (i < m && j < n) {
				if (s[i] == dict[j]) {
					++j;
				}
				++i;
			}
			if (j == n)
				ans = ans == "" || dict.size() > ans.size() || dict < ans ? dict : ans;
		}
		return ans;
	}
};
// @lc code=end

