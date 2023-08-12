   // #include <bits/stdc++.h>
// using namespace std;
class Solution {
public:

void findCombinations(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds, int sum, int idx)
{
    if (sum > target || idx >= candidates.size())
        return;

    if (target == sum)
    {
        ans.push_back(ds);
        return;
    }
    sum += candidates[idx];
    ds.push_back(candidates[idx]);
    findCombinations(candidates, target, ans, ds, sum, idx);

    sum -= candidates[idx];
    ds.pop_back();
    findCombinations(candidates, target, ans, ds, sum, idx + 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(candidates, target, ans, ds, 0, 0);
    return ans;
}

};

// int main()
// {
        // solution s;
//     int n, target;
//     cin >> n >> target;
//     vector<int> arr(n);
//     for (auto &it : arr)
//         cin >> it;

//     vector<vector<int>> ans = s.combinationSum(arr, target);
//     for (auto &it : ans)
//     {
//         for (auto &kt : it)
//         {
//             cout << kt << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }