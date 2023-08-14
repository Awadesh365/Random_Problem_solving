class Solution
{
public:
     void generateSubSets(vector<int> &candidates, int target, int sum, int start, vector<int> &curr, vector<vector<int>> &result)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            curr.push_back(candidates[i]);
            generateSubSets(candidates, target, sum + candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> result;

        generateSubSets(candidates, target, 0, 0, curr, result);
        return result;
    }
};