class Solution {
public:
    int removeElement(vector<int> &nums, int val)
{
    vector<int> test;
    for (auto &it : nums)
    {
        if (it != val)
        {
            test.push_back(it);
        }
    }
    nums.clear();
    for (int i = 0; i < test.size(); i++)
    {
        nums.push_back(test[i]);
    }
    return test.size();
}
};