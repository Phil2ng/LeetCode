/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int c : s)
        {
            switch (c)
            {
            case '{':
            case '[':
            case '(':
                stk.push(c);
                break;

            case '}':
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
                break;
            case ')':
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
                break;

            default:
                break;
            }
        }
        return stk.empty();
    }
};
// @lc code=end
