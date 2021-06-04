// 1.哈希表
// 2.利用数组下标,数值变负.
// 3.利用数组下标,归位

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int num : nums)
        {
            int t = (num + n) % n;
            if (nums[t] < 0)
                return t;
            nums[t] -= n;
        }
        return -1;
    }

    int findRepeatNumber(vector<int> &nums)
    {
        int i = 0, n = nums.size();
        while (i < n)
        {
            if (nums[i] == i)
            {
                ++i;
                continue;
            }
            if (nums[i] == nums[nums[i]])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};