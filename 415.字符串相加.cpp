/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = num1.length(), len2 = num2.length();
        if (len1 < len2)
        {
            swap(len1, len2);
            swap(num1, num2);
        }
        int addbit = 0, i = 0;
        while (i < len2)
        {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            ans += to_string(cur_sum % 10);
            addbit = cur_sum / 10;
            ++i;
        }
        while (i < len1)
        {
            int cur_sum = (num1[i] - '0') + 0 + addbit;
            ans += to_string(cur_sum % 10);
            addbit = cur_sum / 10;
            ++i;
        }
        if (addbit)
            ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

