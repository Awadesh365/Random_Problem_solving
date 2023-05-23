class Solution {
public:
    const int N = 2500;
    vector<int>dp;
    void getRd(){
        for(int i=0;i<N;i++)
            dp.push_back(-1);
    }
    int lis(int i,vector<int>&nums)
    {
        if(dp[i]!=-1)  return dp[i];

        int ans=1;
        for(int j=0;j< i;j++){
            if(nums[i]>nums[j])
                ans=max(ans,lis(j,nums)+1);
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        getRd();
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans = max(ans,lis(i,nums));
        }
    return ans;
    }
};