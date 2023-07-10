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
class Solution {
public:
  int dfs(TreeNode *root)
{
    if (root == NULL)
        return 0;

    // if only one child is not null, then go into recursion
    if (!root->left)
        return 1 + dfs(root->right);
    else if (!root->right)
        return 1 + dfs(root->left);

    // both children are non-null, hence call for both childs
    return 1 + min(dfs(root->left), dfs(root->right));
}
int minDepth(TreeNode *root)
{
    return dfs(root);
}
};