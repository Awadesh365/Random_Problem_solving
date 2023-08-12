class Solution
{
public:
    void findCombinations(vector<int> ds, vector<vector<int>> &ans, int k, int start, int n)
    {

        if (ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            ds.push_back(i);
            findCombinations(ds, ans, k, i + 1, n);
            ds.pop_back();
            // findCombinations(ds, ans, k, i + 1, n);
        }
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(ds, ans, k, 1, n);
        // vector<vector<int>> sol;
        // for (auto &it : ans)
        // {
        //     sol.push_back(it);
        // }
        return ans;
    }
};