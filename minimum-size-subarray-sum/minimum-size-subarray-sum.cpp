class Solution {
public:
   int minSubArrayLen(int target, vector<int> &nums){
    int left = 0, right = 0, currSum = 0;
    int ans = INT_MAX;

    for (right = 0; right < nums.size();right++){
        currSum += nums[right];

        while(currSum>=target){
            ans = min(ans, right - left + 1);
            currSum -= nums[left];
            left++;
        }
    }
    if(ans == INT_MAX)
        return 0;
    else
        return ans;
}

};