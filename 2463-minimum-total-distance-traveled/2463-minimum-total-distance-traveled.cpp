class Solution {
public:
    long long minimumTotalDistance(vector<int>& rob, vector<vector<int>>& fac) 
    {
        sort(rob.begin(), rob.end());
        sort(fac.begin(), fac.end());
        
        int n = rob.size(), m = fac.size();
        vector<long long> dp(n + 1, 1000000000000000);
        dp[0] = 0;
        
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < fac[j][1]; ++k)
                for (int i = n - 1; i >= 0; --i)
                    dp[i+1] = min(abs(rob[i]-fac[j][0]) + dp[i], dp[i+1]);
        
        return dp[n];
    }
};