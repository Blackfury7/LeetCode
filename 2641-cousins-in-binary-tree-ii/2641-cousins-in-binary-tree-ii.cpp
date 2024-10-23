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
    vector<int> l_sum;
    void level_sum(TreeNode* n, int d = 0) {
        if (n == nullptr)
            return;
        l_sum.resize(max((int)l_sum.size(), d + 1));
        l_sum[d] += n->val;
        level_sum(n->left, d + 1);
        level_sum(n->right, d + 1);
    }
    void update_sum(TreeNode* n, int sib_sum, int d = 0) {
        if (n == nullptr)
            return;
        n->val = l_sum[d] - sib_sum;
        sib_sum = (n->left == nullptr ? 0 : n->left->val)
            + (n->right == nullptr ? 0 : n->right->val);
        update_sum(n->left, sib_sum, d + 1);
        update_sum(n->right, sib_sum, d + 1);
    }    
    TreeNode* replaceValueInTree(TreeNode* root) {
        level_sum(root);
        update_sum(root, root->val);
        return root;
    }
};