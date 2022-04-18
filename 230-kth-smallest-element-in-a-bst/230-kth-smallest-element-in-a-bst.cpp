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
    int c=0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        int p=kthSmallest(root->left,k);
        if(p!=-1)return p;
        ++c;
        if(c==k) return root->val;
        return kthSmallest(root->right,k);
    }
};