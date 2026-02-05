// problem: Best Time to Buy and Sell Stock
// platform: LeetCode
// link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// time complexity: O(n)
// space complexity: O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, maxP = 0, minP = INT_MAX;
        for (int p : prices)
        {
            minP = min(minP, p);
            profit = p - minP;
            maxP = max(maxP, profit);
        }
        return maxP;
    }
};