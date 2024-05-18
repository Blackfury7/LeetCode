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
    int distributeCoins(TreeNode* r, TreeNode* p = nullptr) {
      if (r == nullptr) return 0;
      int res = distributeCoins(r->left, r) + distributeCoins(r->right, r);
      if (p != nullptr) p->val += r->val - 1;
      return res + abs(r->val - 1);
    }
};