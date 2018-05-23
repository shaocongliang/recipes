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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> vecs;
        if(root == nullptr) {
            return vecs;
        }
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.empty() == false) {
            std::vector<int> v;
            int size = nodes.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                v.push_back(node->val);
                if(node->left != nullptr) { nodes.push(node->left); }
                if(node->right != nullptr) { nodes.push(node->right); }
                nodes.pop();
            }
            vecs.push_back(v);
        }
        return vecs;
    }
};