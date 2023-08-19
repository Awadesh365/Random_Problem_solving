class Solution {
public:
int findMaximum(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
        return nums[0];

    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int pick = nums[n] + findMaximum(nums, n - 2, dp);

    int not_pick = findMaximum(nums, n - 1, dp);

    return dp[n] = max(pick, not_pick);
}
    int rob(vector<int>& nums) {
         int n = nums.size();
         vector<int>dp(n+1,-1);
     return findMaximum(nums, n-1,dp);
    }
};