class Solution {
public:
// POD
    const int mod = 1000000007;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int score = 0;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int k = 1; k <= high; k++) {
            if (k >= zero) {
                dp[k] += dp[k - zero];
                dp[k] %= mod;
            }
            if (k >= one) {
                dp[k] += dp[k - one];
                dp[k] %= mod;
            }
        }
        
        for (int k = low; k <= high; k++) {
            score += dp[k];
            score %= mod;
        }
        return score;
    }
};