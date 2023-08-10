    const int M = 35;
    vector<int>dp(M,-1);
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return dp[n]= n;

            if(dp[n]!=-1)
                return dp[n];

            return dp[n] =  fib(n-1)+fib(n-2);
    }
};