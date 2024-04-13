class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        if(!size(M)) return 0;
        int ans = 0, m = size(M), n = size(M[0]);
        vector<vector<short>> dp(m+1, vector<short>(n+1));
        for(int i = m-1; ~i; i--) 
            for(int j = n-1; ~j; j--) 
                dp[i][j] = M[i][j] == '1' ? dp[i][j+1] + 1 : 0;
                    
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                for(int row = i, colLen = n; row < m && M[row][j] == '1'; row++)
                    ans = max(ans, (row-i+1) * (colLen = min(colLen, dp[row][j]*1)));
                    
        return ans;
    }
};