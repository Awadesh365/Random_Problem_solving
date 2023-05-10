class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n));

    int top = 0, right = n - 1, left = 0, bottom = n - 1;

    int j = 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = j;
            j++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = j;
            j++;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            ans[bottom][i] = j;
            j++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            ans[i][left] = j;
            j++;
        }
        left++;
    }

    return ans;
}
};