class Solution {
public:
// Approach 1:- using DP (iterative)
typedef long long ll;
ll mostPoints(vector<vector<int>> questions)
{
    ll n = questions.size();
    vector<ll> dp(n);
    dp[n - 1] = questions[n - 1][0];

    for (ll i = (n - 2); i >= 0; --i)
    {
        dp[i] = questions[i][0];
        ll skip = questions[i][1];

        if (i + skip + 1 < n)
            dp[i] += dp[i + skip + 1];

        // dp[i]= max(solv it,skip it);
        dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[0];
}
};