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
    bool dfs(TreeNode *lhs, TreeNode *rhs) {
        if(lhs == nullptr && rhs == nullptr) {
            return true;
        }
        else if(lhs == nullptr && rhs != nullptr) {
            return false;
        }
        else if(lhs != nullptr && rhs == nullptr) {
            return false;
        }
        else{
            return lhs->val == rhs->val && dfs(lhs->left, rhs->right) && dfs(lhs->right, rhs->left);
        }
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return dfs(root->left, root->right);
    }
};