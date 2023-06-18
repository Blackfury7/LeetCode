class Solution {
public:
     int mod=1e9+7;
    vector<pair<int,int>>dirn{{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    bool safe(int a,int b)
    {
        if(a>=0 && b>=0 && a<n && b<m)return 1;
        return 0;
    }
    int solve(int i,int j,vector<vector<int>>& v,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        for(const auto & p:dirn)
        {
            int a=i+p.first, b=j+p.second;
            if(safe(a,b) && v[a][b]>v[i][j])
                ans+=solve(a,b,v,dp);
            
        }
        return dp[i][j]=ans%mod;
    }
public:
    int countPaths(vector<vector<int>>& v) 
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n=v.size();
        m=v[0].size();
        long long ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=(ans+ solve(i,j,v,dp))%mod;
        return ans;
    }
};