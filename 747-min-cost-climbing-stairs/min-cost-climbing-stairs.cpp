class Solution
{
public:
    int returnMinCost(int idx, vector<int> &cost, int n, vector<int> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        return dp[idx] = cost[idx] += min(returnMinCost(idx + 1, cost, n, dp), returnMinCost(idx + 2, cost, n, dp));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(returnMinCost(0, cost, n, dp), returnMinCost(1, cost, n, dp));

        return ans;
    }
};