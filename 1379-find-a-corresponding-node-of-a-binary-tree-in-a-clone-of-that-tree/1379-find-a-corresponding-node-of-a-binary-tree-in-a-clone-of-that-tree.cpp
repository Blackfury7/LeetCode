/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* getTargetCopy(TreeNode* orig, TreeNode* clone, TreeNode* targ) {
//         return orig == nullptr ? nullptr :
//             orig == targ ? clone :
//                 getTargetCopy(orig->left, clone->left, targ) ?: getTargetCopy(orig->right, clone->right, targ);
//     }
// };


//******************************************************************************************************

class Solution {
    void dfs(TreeNode* og, TreeNode* copy, TreeNode* target, TreeNode*& ans) {
        if(!og) return;
        
        if(og == target) {
            ans = copy;
        }
        
        dfs(og->left, copy->left, target, ans);
        dfs(og->right, copy->right, target, ans);
        
        return;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};