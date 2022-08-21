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
    const static int N = 1e5+10;
    int depth[N];
    vector<int> graph[N];
    int ans = 0;
    
    void treeToGraph (TreeNode* root, int parent) {
        if(!root)return;
        if(parent != -1) {
            graph[root->val].push_back(parent);
            graph[parent].push_back(root->val);
        }
        
        treeToGraph(root->left, root->val);
        treeToGraph(root->right, root->val);
        return;
    }
    
    void dfs (int vertex, int parent) {
        if (parent != -1) depth[vertex] = depth[parent] + 1;
        
        ans = max(ans, depth[vertex]);
        for(auto child : graph[vertex]) {
            if(child == parent) continue;
            dfs(child, vertex);
        }
    }
    
    int amountOfTime (TreeNode* root, int start) {
        treeToGraph(root,-1); // making graph
        memset(depth, 0, sizeof(depth)); // depth calculation
        dfs(start, -1);
        return ans;
    }    
    
};