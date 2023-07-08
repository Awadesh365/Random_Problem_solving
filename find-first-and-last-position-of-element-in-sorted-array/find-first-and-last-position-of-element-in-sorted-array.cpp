class Solution {
public:
// using two left's two right's and two mid's -> double binary search

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();

    int firstOccurance = -1, lastOccurance = -1;
    int left1 = 0, left2 = 0, right1 = (n - 1), right2 = (n - 1);

    for (int i = 0; i < n; i++)
    {
        int mid1 = (left1 + right1) / 2;
        int mid2 = (left2 + right2) / 2;

        if (nums[mid1] == target)
        {
            firstOccurance = mid1;
            right1 = mid1 - 1;
        }
        else if (nums[mid1] < target)
            left1 = mid1 + 1;
        else
            right1 = mid1 - 1;

        if (nums[mid2] == target)
        {
            lastOccurance = mid2;
            left2 = mid2 + 1;
        }
        else if (nums[mid2] < target)
            left2 = mid2 + 1;
        else
            right2 = mid2 - 1;
    }
    vector<int> ans={firstOccurance,lastOccurance};

    return ans;
}
};