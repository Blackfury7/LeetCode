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
    vector<TreeNode*> generateTrees(int n) {

        if(n==0)
        return vector<TreeNode*> ();

        vector<TreeNode*> ans = solve(1, n);

        return ans;
        
    }

    vector<TreeNode*> solve(int start, int end)
    {
        vector<TreeNode*> v;

        if(start>end)
        {
            v.push_back(NULL);
            return v;
        }

        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> leftside = solve(start, i-1);
            vector<TreeNode*> rightside = solve(i+1, end);

            for(auto j:leftside)
            {
                for(auto k:rightside)
                {
                    TreeNode* nn = new TreeNode(i);
                    nn->left = j; 
                    nn->right = k;
                    v.push_back(nn);
                }
            }
        }

        return v;
    }
};