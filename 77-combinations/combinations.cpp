class Solution
{
public:
    void findCombinations(vector<int> ds, set<vector<int>> &ans, int k, int start, int n)
    {

        if (ds.size() == k)
        {
            ans.insert(ds);
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

        set<vector<int>> ans;
        vector<int> ds;

        findCombinations(ds, ans, k, 1, n);
        vector<vector<int>> sol;
        for (auto &it : ans)
        {
            sol.push_back(it);
        }
        return sol;
    }
};