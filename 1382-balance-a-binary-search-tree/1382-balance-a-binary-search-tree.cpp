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
    int makeVine(TreeNode *grand, int cnt = 0) {
      auto n = grand->right;
      while (n != nullptr) {
        if (n->left != nullptr) {
          auto old_n = n;
          n = n->left;
          old_n->left = n->right;
          n->right = old_n;
          grand->right = n;
        }
        else {      
            ++cnt;
            grand = n;
            n = n->right;
        }
      }
      return cnt;
    }
    void compress(TreeNode *grand, int m) {
      auto n = grand->right;
      while (m-- > 0) {
        auto old_n = n;
        n = n->right;
        grand->right = n;
        old_n->right = n->left;
        n->left = old_n;
        grand = n;
        n = n->right;
      }
    }
    TreeNode* balanceBST(TreeNode *root) {
      TreeNode grand;
      grand.right = root;
      auto cnt = makeVine(&grand);
      int m = pow(2, int(log2(cnt + 1))) - 1;
      compress(&grand, cnt - m);
      for (m = m / 2; m > 0; m /= 2)
        compress(&grand, m);
      return grand.right;
    }
};