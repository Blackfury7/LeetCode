class Solution {
public:
     int cumsum[51][51];
    
    int dp[51][51][11];
    const int mod = 1e9 + 7;
public:
    int ways(vector<string>& pizza, int K) {
        const int n = pizza.size();
        const int m = pizza[0].size();
        
        memset(cumsum, 0, sizeof(cumsum));
        memset(dp, -1, sizeof(dp));
        
        // fill cumsum
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                cumsum[i][j] = cumsum[i+1][j] + cumsum[i][j+1] - cumsum[i+1][j+1];
                cumsum[i][j] += pizza[i][j] =='A'?1:0;
                
                // base case
                if(cumsum[i][j]>0) dp[i][j][K-1] = 1;
            }
        }
        
        return topDown(0, 0, 0, n, m, K);
                
    }
    
    int topDown(int x, int y, int k, const int& n, const int& m, int& K){
        if(k==K-1) return 1;
        if(dp[x][y][k]>-1) return dp[x][y][k];
        // check for 0 apples in submatrix
        if(cumsum[x][y]==0) return 0;
        
        int ret = 0;
        // horizontal cuts
        for(int i=x+1; i<n; i++){
            // check if cut valid
            if(cumsum[x][y]-cumsum[i][y]){
                ret +=topDown(i, y, k+1, n, m, k);
                ret %= mod;
            }
        }
        
        // vertical cuts
        for(int j=y+1; j<m; j++){
            // check if cut valid
            if(cumsum[x][y]-cumsum[x][j]){
                ret +=topDown(x, j, k+1, n, m, k);
                ret %= mod;
            }
        }
        dp[x][y][k] = ret;
        return ret;
    }
};