//problem: Majority Element II
//platform: LeetCode
//link: https://leetcode.com/problems/majority-element-ii/
//time complexity: O(n)
//space complexity: O(1)



class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        int n = nums.size();
        for (int num : nums)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int num : nums)
        {
            if (candidate1 == num)
            {
                count1++;
            }
            else if (candidate2 == num)
            {
                count2++;
            }
        }
        vector<int> ans;
        if (count1 > n / 3)
        {
            ans.push_back(candidate1);
        }
        if (count2 > n / 3)
        {
            ans.push_back(candidate2);
        }
        return ans;
    }
};