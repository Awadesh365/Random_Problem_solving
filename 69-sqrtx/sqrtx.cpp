class Solution {
public:

typedef long long ll;
int mySqrt(int x)
{
    ll left = 0, right = x;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;

        ll check = (mid * mid), test = (mid + 1) * (mid + 1);
        if (check <= x && test > x)
            return mid;
        else
        {
            if(check<x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return (x - 1);
}

};