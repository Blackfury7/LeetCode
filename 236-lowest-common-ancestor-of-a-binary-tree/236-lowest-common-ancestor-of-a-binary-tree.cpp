/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        // if(root == NULL)return NULL;
        
        if(!root || root == p || root == q)return root;
        
        TreeNode* left = findLCA(root->left, p, q); // if present in left subtree
        TreeNode* right = findLCA(root->right, p, q); // if present in right subtree
        
        // if root is lca i.e. ans 
        if(left && right) return root;
        
        // left subtree or right subtree is lca
        if(left) return left;
         return right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};