class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> freq;
    for (auto &it : nums)
        freq[it]++;

    set<int> ck;
    for (auto &it : nums)
        ck.insert(it);

    vector<pair<int, int>> ans;
    for (auto &it : freq)
        ans.push_back({it.second, it.first});

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    vector<int> sol;
    for(auto &it:ans){
        if(k){
            sol.push_back(it.second);
            k--;
        }
    }

    return sol;
}
};