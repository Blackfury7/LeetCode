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
    int res=0;
    vector<int> helper(TreeNode* root,int distance)
    {
        if(root==NULL)
            return {};
        auto left=helper(root->left,distance);
        auto right=helper(root->right,distance);
        vector<int> ret;
        if(left.size()==0&&right.size()==0)
        { 
            ret.push_back(1);
            return ret;
        }
        for(int i=0;i<left.size();i++)
            for(int j=0;j<right.size();j++)
            {
                if(left[i]+right[j]<=distance)
                    res++;
            }
        for(auto x:left)
            ret.push_back(x+1);
        for(auto x:right)
            ret.push_back(x+1);
        return ret;
    }
    
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return res;
    }
};