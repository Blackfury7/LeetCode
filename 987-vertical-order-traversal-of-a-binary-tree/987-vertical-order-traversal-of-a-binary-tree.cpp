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
 */class Solution {
public:
    map<int,map<int,multiset<int>>> adj;
    void go(TreeNode *root,int r, int c)
    {
        if(!root)
            return ;
        if(root->left)
            adj[c-1][r+1].insert(root->left->val);
        if(root->right)
            adj[c+1][r+1].insert(root->right->val);
        go(root->left,r+1,c-1);
        go(root->right,r+1,c+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        go(root,0,0);
        adj[0][0].insert(root->val);
        for(auto &[k,v]:adj)
        {
            vector<int> te;
            for(auto &x:v)
            {
                for(auto z:x.second)
                    te.push_back(z);
            }
            ans.push_back(te);
        }
        return ans;
    }
};