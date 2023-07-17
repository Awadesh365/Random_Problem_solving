class Solution {
public:
   int mySqrt(int x)
{
    for (long long i = 0; i<= x; i++)
    {
        if (i * i == x)
            return i;

        if(i*i>x)
        {
            return i-1;
        }
    }
    return x-1;
}
};