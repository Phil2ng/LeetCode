/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ways;
        for (int i = 0; i < expression.length(); ++i)
        {
            int op = expression[i];
            if (op == '+' || op == '-' || op == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int &l : left)
                {
                    for (int &r : right)
                    {
                        switch (op)
                        {
                        case '+':
                            ways.push_back(l + r);
                            break;
                        case '-':
                            ways.push_back(l - r);
                            break;
                        case '*':
                            ways.push_back(l * r);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        if (ways.empty())
            ways.push_back(stoi(expression));
        return ways;
    }
};
// @lc code=end
