class Solution {
public:
   int mySqrt(int x)
{
    int ans = 1;
    for (long long i = 0; i<= x; i++)
    {
        if (i * i <= x)
            ans = i;
        else 
            return i-1;
    }
    return ans;
}
};