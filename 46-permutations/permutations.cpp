class Solution {
public:
   void findWaysToArrange(map<int, bool> isMarked, vector<vector<int>> &ans, vector<int> ds, vector<int> &arr)
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    for (auto &it : arr)
    {
        if (!isMarked[it])
        {
            ds.push_back(it);
            isMarked[it] = true;
            findWaysToArrange(isMarked, ans, ds, arr);
            ds.pop_back();
            isMarked[it] = false;
        }
    }
    // ds.pop_back();
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> ans;
    int n = nums.size();
    map<int, bool> isMarked;

    findWaysToArrange(isMarked, ans, ds, nums);
    return ans;
}
};