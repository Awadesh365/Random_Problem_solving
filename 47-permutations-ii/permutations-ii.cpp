class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> results;
        backtrack(results, nums, 0);
        return results;
    }

private:
    void backtrack(vector<vector<int>> &results, vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            results.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); ++i)
        {
            if (used.count(nums[i]))
            {
                continue;
            }

            used.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtrack(results, nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};