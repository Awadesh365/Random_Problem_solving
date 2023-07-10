class Solution {
public:
    int findMin(vector<int> &nums)
{
    int n = nums.size();

    int ans = INT_MAX;

    int left = 0, right = (n - 1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid - 1 >= 0 && mid + 1 <= (n - 1))
        {
            if (nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1])
            {
                ans = nums[mid];
            }
        }
        if (nums[mid] >= nums[left])
        {
            if (nums[left] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else if (left <= (n - 1))
            left++;
    }
    return min(ans, min(nums[0], nums[n - 1]));
}
};