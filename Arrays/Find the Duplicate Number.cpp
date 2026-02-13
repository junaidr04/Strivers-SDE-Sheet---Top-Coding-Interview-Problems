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
        int slow = nums[0], fast = nums[0];   //two pointer declare
        while (true)   //infinity loop because Amra jani cycle thakbei (duplicate guarantee). So eventually slow & fast meet korbei.
        {
            slow = nums[slow];  //Slow 1 step move kore.
            fast = nums[nums[fast]];  //Fast 2 step move kore... Jodi cycle thake, fast eventually slow ke catch korbe.
            if (slow == fast)   //Jodi meet kore → cycle detect hoye geche
                break;
        }
        slow = nums[0];   //Slow ke abar starting e pathalam.
        while (slow != fast)   //Duita ek speed e cholbe.
        {
            slow = nums[slow];   //Because now we are finding entry point of cycle.
            fast = nums[fast];
        }
        return slow;   //That point = cycle start... Cycle start = duplicate number
    }

};
