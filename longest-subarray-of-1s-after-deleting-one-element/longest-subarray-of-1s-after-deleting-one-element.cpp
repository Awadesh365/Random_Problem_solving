class Solution {
public:
    int longestSubarray(vector<int> &nums)
{
    // like how many zeros you're considering, but at the end that should be maximum only 1 zero can be there
    int countOfZeros = 0;

    // from starting to ending considring the maximum of 1 zero and maximum count of 1
    int longestWindow = 0;

    // left most point of the operation space
    int startingPoint = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int it = nums[i];

        if (it == 0)
            countOfZeros++;

        // minimization of zeros in the operation space -> skriking the window
        // number of zeros should be maximum of count 1.

        while (countOfZeros >= 2)
        {
            if (nums[startingPoint] == 0)
                countOfZeros--;

            startingPoint++;
        }
        longestWindow = max(longestWindow, i - startingPoint);
    }
    return longestWindow;
}
};