class Solution {
public:
int longestSubsequence(vector<int> &arr, int difference)
{
    map<int, int> dp;
    int solution = 0;

    for(auto &it:arr){
        int beforeA = dp.count(it - difference) ? dp[it - difference] : 0;

        dp[it] = beforeA + 1;
        solution = max(solution, dp[it]);
    }

    return solution;
}

};