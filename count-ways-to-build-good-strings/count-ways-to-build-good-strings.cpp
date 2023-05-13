class Solution
{
    vector<int> dp;
    int mod = (1e9 + 7);

    int dfs(int end, int zero, int one)
    {
        if (dp[end] != -1)
            return dp[end];

        int cnt = 0;
        if (end >= one)
            cnt += dfs(end - one, zero, one);

        if (end >= zero)
            cnt += dfs(end - zero, zero, one);

        dp[end] = cnt % mod;
        return dp[end];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        dp.resize(high + 1, -1);
        dp[0] = 1;

        int ans = 0;
        for (int end = low; end <= high; ++end)
        {
            ans += dfs(end, zero, one);
            ans %= mod;
        }

        return ans;
    }
};