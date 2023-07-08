class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target)
{

    // optimal sol:- an algorithm with O(log n) runtime complexity

    // best way

    int fir = -1, sec = -1;
    int left = 0, right = (nums.size() - 1);
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            fir = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    left = 0, right = (nums.size() - 1);
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            sec = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return {fir, sec};
}

};