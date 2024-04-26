class Solution {
public:
    int dp[200][200];
    int f(int row,int col,vector<vector<int>> &grid) {
        // base cases
        if(row == grid.size()) return 0;
        if(dp[row][col] != 1e9) return dp[row][col];

        int ans = 1e9;
        for(int c=0;c<grid[0].size();++c) {
            if(c == col) continue;
            ans = min(ans,f(row+1,c,grid));
        }
        if(ans == 1e9) ans = 0;
        return dp[row][col] = grid[row][col] + ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<200;++i) {
            for(int j=0;j<200;++j) {
                dp[i][j] = 1e9;
            }
        }
        int ans = 1e9;
        for(int c=0;c<grid[0].size();++c) {
            ans = min(ans,f(0,c,grid));
        }
        return ans;
    }
};