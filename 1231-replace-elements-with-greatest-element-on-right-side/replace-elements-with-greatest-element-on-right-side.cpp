class Solution {
public:
    vector<int> replaceElements(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = *max_element(arr.begin() + i, arr.end());
    }
    arr[arr.size() - 1] = -1;
    return arr;
}
};