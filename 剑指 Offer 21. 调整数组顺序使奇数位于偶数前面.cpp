// 1.首尾双指针
// 2.快慢双指针

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && (nums[right] & 1) == 0)
                --right;
            while (left < right && (nums[left] & 1) != 0)
                ++left;
            swap(nums[left], nums[right]);
        }
        return nums;
    }

    vector<int> exchange(vector<int> &nums)
    {
        for (int fast = 0, slow = 0; fast < nums.size(); ++fast)
        {
            if (nums[fast] & 1)
            {
                swap(nums[fast], nums[slow++]);
            }
        }
        return nums;
    }
};
