/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *node, int remainer) {
        if(node == nullptr) {
            return false;
        }
        if(node->val == remainer && node->left == nullptr && node->right == nullptr) {
            return true;
        }
        return dfs(node->left, remainer-node->val) || dfs(node->right, remainer-node->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) {
            return false;
        }
        return dfs(root, sum);
        
    }
};