class Solution {
public:
  int searchInsert(vector<int> &nums, int target)
{
    return equal_range(nums.begin(), nums.end(), target).first - nums.begin();
}
};