class Solution {
public:
int largestVariance(string s)
{
    int n = s.size();
    int ans = 0;

    // two char for comparision
    // hyFreq for the one with higher frequency
    // lwFreq for the one with lower frequency

    for (char hyFreq = 'a'; hyFreq <= 'z'; hyFreq++)
    {
        for (char lwFreq = 'a'; lwFreq <= 'z'; lwFreq++)
        {
            if (hyFreq != lwFreq)
            {

                // using the notion of Kadane's algo
                int hyCount = 0; // for the higher one
                int lwCount = 0; // for the lower one

                // flag to handle corner cases
                bool canPrevLwBeExtended = false;

                for (auto &it : s)
                {
                    if (it == hyFreq)
                        hyCount++;

                    if (it == lwFreq)
                        lwCount++;

                    // an interval should contain at least one lwFreq
                    if (lwCount > 0)
                        ans = max(ans, hyCount - lwCount);

                    // corner case:consider previous lwFreq
                    else if (lwCount == 0 && canPrevLwBeExtended)
                        ans = max(ans, hyCount - 1);

                    /*
                        reset if the number of occurrences of character represented
                        by 'lwFreq' is greater than the number of occurences of
                        the character represented by 'hyFreq' within a specific interval,
                        the code resets the couhts and starts a new interval.
                        this ensures that each interval considered
                        for comparision contains at leadst one occurences of 'lwFreq'
                    */
                    if (lwCount > hyCount)
                    {
                        lwCount = hyCount = 0;

                        // once reset, the interval can be extended
                        // as there must be 'lwFreq' before the next interval
                        canPrevLwBeExtended = true;
                    }
                }
            }
        }
    }
        return ans;
}
};