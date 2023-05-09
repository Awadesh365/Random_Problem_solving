class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // Optimal sol:-tmComp:- O(n*m)
    int rowSize = matrix.size(), colSize = matrix[0].size();
    int top = 0, left = 0, right = (colSize - 1), bottom = (rowSize - 1);

    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);

        top++;
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);

            left++;
        }
    }
    return ans;
}
};