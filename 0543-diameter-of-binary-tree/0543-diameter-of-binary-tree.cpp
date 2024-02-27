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
    int ans;
    int dfs_diameter(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs_diameter(root->left);
        int right = dfs_diameter(root->right);
        
        ans = max(ans, left + right);
        
        return 1 + max(left, right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        dfs_diameter(root);
        return ans;
    }
};