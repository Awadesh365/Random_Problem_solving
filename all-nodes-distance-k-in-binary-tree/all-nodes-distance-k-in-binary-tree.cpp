// #include<bits/stdc++.h>
// using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> ans;

    // understaning probs related to dfs,bfs, trees etc.
    // POD -> NM -> LDI=> udr_std.

    int dfs(TreeNode *root,TreeNode *target,int dist, int k){
        if(!root || dist > k)
            return 0;

        if(root == target){
            // check the target node and start to record the distance
            dfs(root->left, target, 1, k);
            dfs(root->right, target, 1, k);
            return 1;
        }
        int l = dfs(root->left, target, dist + (dist > 0), k);
        int r = dfs(root->right, target, dist + (dist > 0), k);

        if(dist==k || l == k || r == k)
            ans.push_back(root->val);
            // if the distance is k, push to the result vector
        
        // we do not hope that the target node path is visited repeatedly
        if(l){
            dfs(root->right, target, l + 1, k);
            return l + 1;
        }
        if(r){
            dfs(root->left, target, r + 1, k);
            return r + 1;
        }
        return 0;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if(!k)
            return {target->val}; // exception for k = 0;

        ans = vector<int>();
        dfs(root, target, 0, k);

        return ans;
    }
};

// int main(){
//     return 0;
// }