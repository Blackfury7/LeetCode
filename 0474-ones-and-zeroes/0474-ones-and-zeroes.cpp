class Solution {
public:
    int dp[605][105][105];
    
    int func(int ind, int m, int n, vector<pair<int, int>>& v) {
        if((m == 0 and n == 0) or ind < 0) return 0;
        if(dp[ind][m][n] != -1) return dp[ind][m][n]; 
        
        int ans = func(ind -1, m, n, v);
        if(m >= v[ind].first and n >= v[ind].second)
            ans = max(ans, func(ind -  1, m - v[ind].first, n - v[ind].second, v) + 1);
        return dp[ind][m][n] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        int N = strs.size();
        vector<pair<int, int>> v;
        int zeros, ones;
        for(int i = 0; i < N; i++) {
            zeros = 0;
            for(auto &ch: strs[i])
                zeros += (ch=='0');
            
            ones = strs[i].size() - zeros;
            v.push_back({zeros, ones});
        }
        // for(auto&[i,j]:v)cout<<i<<" "<<j<<"\n";
        
        return func(N-1, m, n, v);
        
    }
};