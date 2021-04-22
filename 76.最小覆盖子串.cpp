/*
 * 滑动窗口 指针遍历
 * 
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string S, string T) {
		vector<bool> flag(128, false);
		vector<int> chars(128, 0);
		int m = S.size(), n = T.size();
		//统计T中字符情况
		for (int i = 0; i < n; ++i) {
			flag[T[i]] = true;
			++chars[T[i]];
		}
		//移动滑动窗口，不断更新数据
		int cnt = 0, l = 0, r = 0, min_l = 0, min_r = m;
		for (r = 0; r < m; ++r) {
			if (!flag[S[r]])
				continue;
			if (--chars[S[r]] >= 0)
				++cnt;
			//若目前滑动窗口包含所有T中字符，则尝试将l右移，在不影响结果的情况下获得最短字符串。
			while (cnt == n) {
				if (r - l + 1 < min_r - min_l + 1) {
					min_l = l;
					min_r = r;
				}
				if (flag[S[l]] && ++chars[S[l]] > 0)
					--cnt;
				++l;
			}
		}
		return min_r - min_l + 1 > m ? "" : S.substr(min_l, min_r - min_l + 1);
	}
};
// @lc code=end

