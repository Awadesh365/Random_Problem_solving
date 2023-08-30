class Solution
{
public:
    void generateSubsets(vector<int> &nums, int idx,
                         vector<int> temp, vector<vector<int>> &ans)
    {
        if (idx >= nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        generateSubsets(nums, idx + 1, temp, ans);
        temp.pop_back();

        while (idx < nums.size() - 1 && nums[idx] == nums[idx + 1])
            idx++;

        generateSubsets(nums, idx + 1, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        generateSubsets(nums, 0, temp, ans);

        return ans;
    }
};