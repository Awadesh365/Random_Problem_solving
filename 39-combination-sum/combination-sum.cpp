class Solution
{
public:
  void subArray(int idx, vector<int> &ds, int trg, vector<int> &candidates, vector<vector<int>> &ans){
    if (idx == candidates.size()){
      if (trg == 0){
        ans.push_back(ds);
      }
      return;
    }
    if (candidates[idx] <= trg){
      ds.push_back(candidates[idx]);
      subArray(idx, ds, trg - candidates[idx], candidates, ans);
      ds.pop_back();
    }
    subArray(idx + 1, ds, trg, candidates, ans);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    subArray(0, ds, target, candidates, ans);

    return ans;
  }
};
