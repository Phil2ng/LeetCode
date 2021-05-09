/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> nums, ops;
        unordered_map<char, int> mp;
        mp['+'] = mp['-'] = 1;
        mp['*'] = mp['/'] = 2;
        int num = 0, ans = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            char cur = s[i];
            if (isdigit(cur))
            {
                num = num * 10 + int(cur - '0');
            }
            else if (cur == ' ')
            {
                continue;
            }
            else
            {
                while (!ops.empty() && mp[ops.top()] >= mp[cur])
                {
                    num = opNum(nums.top(), num, ops.top());
                    ops.pop(), nums.pop();
                }
                nums.push(num);
                ops.push(cur);
                num = 0;
            }
        }
        while (!nums.empty() && !ops.empty())
        {
            num = opNum(nums.top(), num, ops.top());
            ops.pop(), nums.pop();
        }
        ans = num;
        return ans;
    }

    int opNum(int a, int b, char op)
    {
        int sum;
        switch (op)
        {
        case '+':
            sum = (a + b);
            break;
        case '-':
            sum = (a - b);
            break;
        case '*':
            sum = (a * b);
            break;
        case '/':
            sum = (a / b);
            break;
        }
        return sum;
    }
};
// @lc code=end
