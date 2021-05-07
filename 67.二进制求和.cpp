/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len1 = a.length(), len2 = b.length();
        if (len1 < len2)
        {
            swap(len1, len2);
            swap(a, b);
        }
        int i = 0, addbit = 0;
        while (i < len2)
        {
            int c = a[i] - '0' + b[i] - '0' + addbit;
            ans += (char)(c % 2 + '0');
            addbit = c / 2;
            ++i;
        }
        while (i < len1)
        {
            int c = a[i] - '0' + addbit;
            ans += (char)(c % 2 + '0');
            addbit = c / 2;
            ++i;
        }
        if (addbit)
            ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

