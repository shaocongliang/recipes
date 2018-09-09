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
    TreeNode *ans;
    bool dfs(TreeNode *node, TreeNode *p, TreeNode *q) {
        if(node == nullptr) { return false;}
        bool b1 = false, b2 = false, b3 = false;
        if(node == p ||  node == q) {
            b2 = true;
        }
        b1 = dfs(node->left, p, q);
        b3 = dfs(node->right,p, q);
        if(b2 && (b1 || b3)) ans = node;
        if(b1 && b3) ans = node;
        if(b1 || b2 || b3) return true;
        else return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};