/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // learned how to use dfs in problems
    // POD
    vector<int>nodeValues;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root->left);
        nodeValues.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        int minDiff = INT_MAX;
        for (int i = 1; i < nodeValues.size(); i++)
        {
            minDiff = min(minDiff, nodeValues[i] - nodeValues[i - 1]);
        }
        return minDiff;
    }
};