// NM...POD
// FS_..B...EXMS
class Solution
{
public:
    // __popcount works only in c++20 and onwards
    int minFlips(int a, int b, int c)
    {
        return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ((a | b) ^ c));
    }
};