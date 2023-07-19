bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}



class Solution {
public:
    // #include <bits/stdc++.h>
// using namespace std;


int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    // for (vector<int> &arr : intervals)
    //     reverse(arr.begin(), arr.end());

    sort(intervals.begin(), intervals.end(),compareSecondElement);

    int ans = 0;
    int k = INT_MIN;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= k)
            k = intervals[i][1];
        else
            ans++;
    }

    // cout << ans << endl;
    // cout << k << endl;

    return ans;

    // for (auto &it : intervals)
    // {
    //     for (auto &kt : it)
    //         cout << kt << " ";

    //     cout << endl;
    // }
}

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> arr(n, vector<int>(2));
//     for (auto &it : arr)
//     {
//         for (auto &kt : it)
//         {
//             cin >> kt;
//         }
//     }
//     cout << eraseOverlapIntervals(arr) << endl;

//     return 0;
// }
};