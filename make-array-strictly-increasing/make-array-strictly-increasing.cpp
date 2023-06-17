class Solution {
private:
// NM
    int helper(int curr, int left, vector<int>& nums1, vector<int>& nums2, vector<unordered_map<int, int>>& dp) {
        if (curr == nums1.size())
            return 0;

        if (dp[curr].find(left) != dp[curr].end())
            return dp[curr][left];

        int exclude, include;

        if (nums1[curr] > left)
            exclude = helper(curr + 1, nums1[curr], nums1, nums2, dp);
        else
            exclude = INT_MAX;

        int rep = upper_bound(nums2.begin(), nums2.end(), left) - nums2.begin();

        if (rep == nums2.size())
            include = INT_MAX;
        else
            include = helper(curr + 1, nums2[rep], nums1, nums2, dp);

        if (include == INT_MAX)
            dp[curr][left] = exclude;
        else
            dp[curr][left] = min(exclude, include + 1);

        return dp[curr][left];
    }

public:
    int makeArrayIncreasing(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        vector<unordered_map<int, int>> dp(nums1.size() + 1);

        int result = helper(0, INT_MIN, nums1, nums2, dp);

        if (result == INT_MAX)
            return -1;

        return result;
    }
};
