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
    void dfs(TreeNode* cur, vector<int>& res, int height) {
        if (!cur)
            return;
        if (height >= res.size())
            res.push_back(cur->val);
        else
            res[height] = max(res[height], cur->val);
        dfs(cur->left, res, height + 1);
        dfs(cur->right, res, height + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        int height = 0;
        dfs(root, res, height);
        return res;
    }
};