#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long n = bloomDay.size();
        long long tst = (long long)m * k;
        if (n < (tst))
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int sol = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int ans = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (mid >= bloomDay[i])
                {
                    cnt++;
                    // cout << cnt << " " << day << endl;
                }
                else
                {
                    ans += (cnt / k);
                    // cout << ans << endl;
                    cnt = 0;
                }

                // cout << ans << endl;
            }
            ans += (cnt / k);
            if (ans >= m)
            {
                sol = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return sol;
    }
};

// int main()
// {
//     Solution s;

//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (auto &it : arr)
//         cin >> it;

//     int m, k;
//     cin >> m >> k;

//     cout << s.minDays(arr, m, k) << endl;

//     return 0;
// }