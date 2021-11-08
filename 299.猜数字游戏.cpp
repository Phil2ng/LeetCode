/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * 遍历模拟
 * 
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0, n = secret.length();
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++)
            cows += min(cntS[i], cntG[i]);
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
// @lc code=end

