// problem: Find the Duplicate Number
// platform: LeetCode
// link: https://leetcode.com/problems/find-the-duplicate-number/description/
// time complexity: 0(n) [Single pass to find the duplicate number]
// space complexity: O(n) [Using a hash map to store frequencies, but we can optimize it to O(1) using the "Floyd's Tortoise and Hare" algorithm]

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); i++)
        {
            freqMap[nums[i]]++;
            if (freqMap[nums[i]] > 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// using Floyd’s Tortoise and Hare Algorithm
// time complexity: O(n) [floyd's cycle detection algorithm]
// space complexity: O(1) [constant space usage]

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};