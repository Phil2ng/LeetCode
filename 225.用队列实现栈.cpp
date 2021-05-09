/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyStack
{
    queue<int> que;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int n = que.size();
        que.push(x);
        for (int i = 0; i < n; ++i)
        {
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ret = que.front();
        que.pop();
        return ret;
    }

    /** Get the top element. */
    int top()
    {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
