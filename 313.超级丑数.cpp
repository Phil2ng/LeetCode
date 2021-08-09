/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * 最小堆,或者动态规划
 * 
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1LL);
        unordered_set<long long> st;
        st.insert(1LL);
        int k = primes.size();
        for (int i = 1; i < n; ++i)
        {
            long long cur = pq.top();
            pq.pop();
            for (int j = 0; j < k; ++j)
            {
                long long num = cur * primes[j];
                if (!st.count(num))
                {
                    pq.push(num);
                    st.insert(num);
                }
            }
        }
        return (int)pq.top();
    }
};
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int m = primes.size();
        vector<int> ans, idx(m, 0);
        ans.push_back(1);
        while (--n)
        {
            int minNum = INT_MAX, num;
            for (int i = 0; i < m; i++)
            {
                num = primes[i] * ans[idx[i]];
                if (minNum > num)
                    minNum = num;
            }
            ans.push_back(minNum);
            for (int i = 0; i < m; i++)
            {
                num = primes[i] * ans[idx[i]];
                if (minNum == num)
                    idx[i]++;
            }
        }
        return ans.back();
    }
};
// @lc code=end

