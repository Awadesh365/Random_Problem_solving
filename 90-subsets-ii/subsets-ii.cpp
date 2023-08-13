class Solution {
public:
   void generateSubSets(vector<int> &nums, set<vector<int>> &powerSet, vector<int> subSet, int index)
{
    if (index >= nums.size())
    {
        sort(subSet.begin(), subSet.end());
        powerSet.insert(subSet); // that set is has exceed the size of array.
        return;
    }

    subSet.push_back(nums[index]);                      // we are considering the element of that index.
    generateSubSets(nums, powerSet, subSet, index + 1); // to the next index of the array we have.
    subSet.pop_back();                                  // we have removed that element so that we can not consider that and check without that element.
    generateSubSets(nums, powerSet, subSet, index + 1); // the case when we moved forward and not considerd the element.
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> powerSet;
    vector<int> subSet;
    generateSubSets(nums, powerSet, subSet, 0);

    vector<vector<int>> finalSolWithoutDuplicates;
    for (auto &it : powerSet)
        finalSolWithoutDuplicates.push_back(it);

    return finalSolWithoutDuplicates;
}
};