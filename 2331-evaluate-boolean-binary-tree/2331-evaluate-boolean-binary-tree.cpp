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
    bool evaluateTree(TreeNode* n) {
        switch(n->val) {
        case 0:
        case 1:
            return n->val;
        case 2:
            return evaluateTree(n->left) || evaluateTree(n->right);
        default:
            return evaluateTree(n->left) && evaluateTree(n->right);
    }
    }
};