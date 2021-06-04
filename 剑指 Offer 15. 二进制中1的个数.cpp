// 1.逐位计数
// 2.位运算性质 n &(n - 1)

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            ans++;
            n = n & (n - 1);
            // ans += n % 2;
            // n >>= 1;
        }
        return ans;
    }
};