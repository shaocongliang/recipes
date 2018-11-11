class Solution {
 public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    b1 = b2 = false;
    int sum = 0;
    inOrder(root, L, R, sum);
    return sum;
  }
  void inOrder(TreeNode *node, int L, int R, int &sum){
    if(node == NULL)
      return;
    inOrder(node->left, L, R, sum);
    if(node->val >= L && node->val <= R){
      sum += node->val;
      if(node->val == L) b1 = true;
      if(node->val == R) b2 = true;
    }
    if(b1 && b2) return;
    inOrder(node->right, L, R, sum);
  }
 private:
  bool b1, b2;
};
