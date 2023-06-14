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
    void inorder(TreeNode * root , int &prev,int &mini)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,prev,mini);
        mini=min(mini,abs(prev-root->val));
        prev = root->val;
        inorder(root->right,prev,mini);
    }


    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int prev = INT_MAX/2;
        inorder(root,prev,mini);
        return mini;        
    }
};