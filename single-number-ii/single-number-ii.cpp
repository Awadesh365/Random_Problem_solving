class Solution {
public:
  int singleNumber(vector<int> &nums)
{
    map<int, int> freq;
    for (auto &it : nums)
        freq[it]++;

    for (auto &it : nums)
    {
        if (freq[it] == 1)
            return it;
    }

    return -1;
}
};