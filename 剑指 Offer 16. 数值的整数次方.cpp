// 快速幂,二分法

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1, t = x;
        long m = n;
        if (m < 0)
        {
            m = -m;
            t = 1 / t;
        }
        while (m)
        {
            if (m & 1)
            {
                ans *= t;
            }
            t *= t;
            m >>= 1;
        }
        return ans;
    }
};