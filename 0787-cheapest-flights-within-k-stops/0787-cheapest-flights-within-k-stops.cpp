class Solution {
public:
    int dfs(vector<vector<pair<int,int>>> &adj,int dst,int src,int k,vector<vector<int>> &dp){   
       
        // here decreasing k will prevent infinite loop
        
        if(src == dst) return 0;
        
        if(k < 0) return INT_MAX;
        
        if(dp[src][k] != -1) return dp[src][k];
        
        int ans = INT_MAX;
        
        for(auto i:adj[src]){
            
                int curr = dfs(adj,dst,i.first,k-1,dp);
                
                if(curr != INT_MAX) ans = min(ans,i.second+curr);            
        }
        
        dp[src][k] = ans;
        
        return ans;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &i:flights) adj[i[0]].push_back({i[1],i[2]});
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        int ans = dfs(adj,dst,src,k,dp);
        
        return ans == INT_MAX ? -1 : ans ;
        
       
        return -1;
    
    }
};