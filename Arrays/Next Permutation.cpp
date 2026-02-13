// problem: Next Permutation
// platform: LeetCode
// link: https://leetcode.com/problems/next-permutation/description/
// time complexity: O(n) [Single pass to find the next permutation]
// space complexity: O(1) [In-place modification of the array]

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};