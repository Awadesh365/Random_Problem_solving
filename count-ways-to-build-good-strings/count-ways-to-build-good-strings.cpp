class Solution
{
    vector<int> dp; // Vector to store the results of subproblems
    int mod = (1e9 + 7); // Modulus value for the final answer

    int dfs(int end, int zero, int one) // Helper function to count the number of good strings of length "end"
    {
        if (dp[end] != -1) // If we have already computed the result for this subproblem, return it.
            return dp[end];

        int cnt = 0; // Counter variable to store the number of good strings of length "end"

        // If we can add "one" to the end of the string, we add it and recursively count the number of good strings for the remaining length
        if (end >= one)
            cnt += dfs(end - one, zero, one);

        // If we can add "zero" to the end of the string, we add it and recursively count the number of good strings for the remaining length
        if (end >= zero)
            cnt += dfs(end - zero, zero, one);

        dp[end] = cnt % mod; // Store the result for this subproblem to avoid recomputing it later
        return dp[end]; // Return the result
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        dp.resize(high + 1, -1); // Initialize the "dp" vector with -1
        dp[0] = 1; // There is only one way to form a string of length zero, which is the empty string.

        int ans = 0; // Variable to store the final answer
        for (int end = low; end <= high; ++end) // Loop through all possible lengths between "low" and "high"
        {
            ans += dfs(end, zero, one); // Count the number of good strings for length "end" and add it to the final answer
            ans %= mod; // Take the modulus to avoid integer overflow
        }

        return ans; // Return the final answer
    }
};
