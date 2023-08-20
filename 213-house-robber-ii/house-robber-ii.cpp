class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // Two cases: either we rob the first house or we don't.
        // 1. If we rob the first house, then we can't rob the last house.
        // 2. If we don't rob the first house, then we can rob the last house.

        // Calculate maximum without considering the last house (0 to n-2)
        int max1 = robHelper(nums, 0, n - 2);

        // Calculate maximum without considering the first house (1 to n-1)
        int max2 = robHelper(nums, 1, n - 1);

        // Return the maximum of the two cases.
        return max(max1, max2);
    }

    int robHelper(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;

        for (int i = start; i <= end; i++) {
            int temp = max(curr, prev + nums[i]);
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};
