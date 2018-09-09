/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root):node_(root) {
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(node_) return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return dfs(&node_);
    }
private:
    int dfs(TreeNode **t) {
        if((*t)->left)
            return dfs(&((*t)->left));
        else {
            auto p = *t;
            *t = (*t)->right;
            return p->val;
        }
    }
    TreeNode *node_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */