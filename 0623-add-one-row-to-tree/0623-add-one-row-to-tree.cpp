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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // exit case: empty tree
        if (!root) return root;
        // edge case: d == 1
        if (d == 1) return new TreeNode(v, root, NULL);
        // right depth reached!
        if (d == 2) {
            root->left = new TreeNode(v, root->left, NULL);
            root->right = new TreeNode(v, NULL, root->right);
            // stopping the recursion
            return root;
        }
        // recursive calls
        addOneRow(root->left, v, d - 1);
        addOneRow(root->right, v, d - 1);
        return root;
    }
};