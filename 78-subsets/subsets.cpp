class Solution {
public:
   vector<vector<int>> ans;
void sub(int n, vector<int>&ds,int idx,vector<int>&nums){
    if(idx >= n){
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[idx]);
    sub(n, ds, idx + 1,nums);

    ds.pop_back();
    sub(n, ds, idx + 1,nums);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int>ds;
    sub(nums.size(),ds,0,nums);
    return ans;
}

};