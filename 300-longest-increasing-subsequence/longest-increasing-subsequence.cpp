class Solution {
public:
    int lis(vector<int>&dp, int index,vector<int>&nums){
        if(dp[index] != -1 ) return dp[index];
        int ans = 1;

        for(int i = 0;i<index;++i ){
            if(nums[index] > nums[i])
                ans = max(ans,lis(dp,i,nums)+1);
        }
        return dp[index] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {

        vector<int>dp(nums.size()+1,-1);
        int ans = 1;
        int i = -1;
        for(auto &it:nums){
            i++;
            ans = max(ans,lis(dp,i,nums));
        }
        return ans;
    }
};