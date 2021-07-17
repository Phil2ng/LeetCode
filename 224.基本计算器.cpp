/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
    stack<char> ops;
    stack<int> nums;
    unordered_map<char, int> priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}, {'(', 100}};

public:
    int calculate(string &s)
    {
        s = "(" + s + ")";
        int n = s.size();
        for (size_t i = 0; i < n; i++)
        {
            char c = s[i];
            if (c == ' ')
                continue;
            else if (c == '(')
                ops.push(c);
            else if (c == ')')
            {
                while (!ops.empty() and ops.top() != '(')
                    calc();
                ops.pop();
            }
            else if (isdigit(c))
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i = i - 1;
                nums.push(num);
            }
            else if (priority.count(c))
            {
                int j = i - 1;
                while (j >= 0 && s[j] == ' ')
                    j--;
                if ((c == '+' || c == '-') && priority.count(s[j]))
                    nums.push(0);
                else
                    while (!ops.empty() && priority[c] >= priority[ops.top()])
                        calc();
                ops.push(c);
            }
        }
        return nums.top();
    }
    void calc()
    {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        int num;
        switch (op)
        {
        case '+':
            num = a + b;
            break;
        case '-':
            num = a - b;
            break;
        case '*':
            num = a * b;
            break;
        case '/':
            num = a / b;
            break;
        case '%':
            num = a % b;
            break;
        case '^':
            num = pow(a, b);
            break;
        default:
            break;
        }
        nums.push(num);
    }
};
// @lc code=end

