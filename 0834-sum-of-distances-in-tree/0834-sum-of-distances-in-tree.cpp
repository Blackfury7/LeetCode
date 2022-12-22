class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& child, vector<int>& ans)
    {
        child[node] = 1;
        for(auto it: adj[node])
        {
            if(it==parent)
                continue;
            dfs(it, node, adj, child,ans);
            child[node] += child[it];
            ans[node] += (ans[it]+child[it]);
        }
    }
    void dfs1(int node, int parent, vector<vector<int>>& adj, vector<int>& child, vector<int>& ans)
    {
        for(auto it: adj[node])
        {
            if(it==parent)
                continue;
            int parentans = ans[node];
            int an = parentans- child[it] + (ans.size()-child[it]);
            ans[it] = an;
            dfs1(it, node, adj, child, ans);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>child(n,0);
        vector<int>ans(n,0);
        dfs(0, -1, adj, child, ans);
        dfs1(0,-1, adj, child, ans);
        return ans;
    }
};
