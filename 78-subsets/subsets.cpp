class Solution {
public:
void findSubSets(int idx, vector<int> &ds, vector<int> &arr, int n, vector<vector<int>> &ans)
{
    if (idx == n)
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(arr[idx]);
    findSubSets(idx + 1, ds, arr, n, ans);
    ds.pop_back();
    findSubSets(idx + 1, ds, arr, n, ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
         vector<int> ds;
         int n = nums.size();

         findSubSets(0, ds,nums, n, ans);

        return ans;
    }
};