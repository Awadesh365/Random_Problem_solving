class Solution {
public:
   void generateSubSets(vector<int> &nums, vector<vector<int>> &powerSet, vector<int> subSet, int index)
{
    if (index >= nums.size())
    {
        powerSet.push_back(subSet); // that set is has exceed the size of array.
        return;
    }

    subSet.push_back(nums[index]);                      // we are considering the element of that index.
    generateSubSets(nums, powerSet, subSet, index + 1); // to the next index of the array we have.
    subSet.pop_back();                                  // we have removed that element so that we can not consider that and check without that element.

    while (index < nums.size() - 1 && nums[index] == nums[index + 1]) // to skip all the duplicate elements, since they're already sorted.
        index++;

    generateSubSets(nums, powerSet, subSet, index + 1); // the case when we moved forward and not considerd the element.
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // so that the duplicate elements will be contigious and easy to skip.

    vector<vector<int>> powerSet;
    vector<int> subSet;
    generateSubSets(nums, powerSet, subSet, 0);

    return powerSet;
}
};