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
    bool dfs(TreeNode* root, int target, int sum) {

        if(target == sum and !(root->left) and !(root->right)) return true;
        if(!root) return false;
        
        if(root->left and dfs(root->left, target, sum + root->left->val)) return true;
        if(root->right and dfs(root->right, target, sum + root->right->val)) return true;
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, targetSum, root->val);
    }
};