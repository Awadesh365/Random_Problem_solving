// #include <bits/stdc++.h>
// using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = (n - 1);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            /*--------------------------------------------------------------------------------------------------------------*/
            /*
            for handeling the corner cases of repeating elements
            consider this eg :-
            size:- 5 target:- 0
            array:-  1 0 1 1 1
             */
            if (nums[mid] == nums[left] && nums[mid] == nums[right])
                // while (nums[mid] == nums[left] && nums[mid] == nums[right] && left < mid && right > mid)
                {
                    left++;
                    right--;
                }
            /*-------------------------------------------------------------------------------------------------------*/
            else
            {
                if (nums[mid] >= nums[left]) // definitely the left portion of list is sorted
                {
                    if (nums[left] <= target && nums[mid] >= target)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                // then right portion will be sorted, since this array is rotated only once.
                else
                {
                    if (nums[mid] <= target && target <= nums[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return false;
    }
};

// int main()
// {
//     Solution s;

//     int n, trg;
//     cin >> n >> trg;

//     vector<int> arr(n);
//     for (auto &it : arr)
//         cin >> it;

//     bool ans = s.search(arr, trg);

//     cout << ans << endl;
//     return 0;
// }
