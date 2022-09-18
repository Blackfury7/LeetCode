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
        // preorder traversal
        void dfs (TreeNode* a, TreeNode* b, int level) {
            if(!a || !b) return;
            if(level & 1) {
                cout<<level<<endl;
                swap(a->val, b->val);
            }
            dfs(a->left, b->right, level+1);
            dfs(a->right, b->left, level+1); 
        }

    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* ans;
        
        // preorder traversal
        dfs(root->left, root->right, 1) ;
        
        return root;
    }
};