// 数学规律题
// 尽量分成 3

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 3)
            return 1;
        if (n == 3)
            return 2;
        long ans = 1;
        while (n > 4)
        {
            ans *= 3;
            ans %= 1000000007;
            n -= 3;
        }
        ans = (n * ans) % 1000000007;
        return ans;
    }
};