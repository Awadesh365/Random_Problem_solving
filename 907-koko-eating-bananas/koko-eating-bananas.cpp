class Solution {
public:
   int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    int test = right;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long ans = 0;

        for (auto &it : piles)
        {
            ans += (ceil((double)it / mid));
            // cout << ceil((double)it / (double)mid) << " ";
        }
        // cout << endl;
        if (ans <= h)
        {
            test = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return test;
}
};