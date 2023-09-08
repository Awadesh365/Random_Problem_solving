/**
 * Definition for a binary tree node.
 */
  // struct TreeNode {
  //     int val;
  //     TreeNode *left;
  //     TreeNode *right;
  //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  // };
class Solution {
public:
   
vector<int> preorderTraversal(TreeNode* root) {
  vector < int > preOrder;
  if (root == NULL)
    return preOrder;

  stack < TreeNode * > s;
  s.push(root);

  while (!s.empty()) {
    TreeNode * topNode = s.top();
    preOrder.push_back(topNode -> val);
    s.pop();
    
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}
};