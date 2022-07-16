class Solution {
    const int mod = 1e9 + 7, 
    moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}}; 
    public:    
    
    bool outOfBounds(int m, int n, int r, int c) {
        return r < 0 || r >= m || c < 0 || c >= n;
    }
    
    int findPaths(int m, int n, int maxMove, int r, int c) {        
        bool isOut = outOfBounds(m, n, r, c);
        
        if(isOut || !maxMove) 
            return isOut;
        
        if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  
        
        dp[r][c][maxMove] = 0;
        for(int i = 0; i < 4; i++) 
            dp[r][c][maxMove] = (dp[r][c][maxMove] + 
                                 findPaths(m, n, maxMove-1, r + moves[i][0], c + moves[i][1])) % mod;
        
        return dp[r][c][maxMove];
    }
};