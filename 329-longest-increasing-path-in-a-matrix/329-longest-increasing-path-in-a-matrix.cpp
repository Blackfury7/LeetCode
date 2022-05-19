class Solution {
public:
    
//     bool checkLimits(int i, int j, int n, int m){
        
//         return (i>=0 and i<n and j>=0 and j<m);
        
        
//     }
    
//     int func(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int n, int m){
        
//         if(!checkLimits(i, j, n, m)) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int c1 = 0, c2 = 0, c3 = 0, c4 =0;
        
//         if(checkLimits(i+1, j, n, m) and matrix[i+1][j]>matrix[i][j]){
//             c1 = func(matrix, dp, i+1, j, n, m);
//         }
        
//         if(checkLimits(i-1, j, n, m) and matrix[i-1][j]>matrix[i][j]){
//             c2 = func(matrix, dp, i-1, j, n, m);
//         }
        
//         if(checkLimits(i, j+1, n, m) and matrix[i][j+1]>matrix[i][j]){
//             c3 = func(matrix, dp, i, j+1, n, m);
//         }
        
//         if(checkLimits(i, j-1, n, m) and matrix[i][j-1]>matrix[i][j]){
//             c4 = func(matrix, dp, i, j-1, n, m);
//         }
        
//         dp[i][j] = 1 + max(c1, max(c2, max(c3, c4)));
        
//         return dp[i][j];        
        
//     }
    
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
        
//         int n = matrix.size(), m = matrix[0].size();
//         int ans = 1;
//         vector<vector<int>> dp(n, vector<int> (m, -1));
        
//         for(int i = 0; i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(dp[i][j]==-1){
//                     ans = max(ans, func(matrix, dp, i, j, n, m));
//                 }
//             }
//         }
//         return ans;
        
        
        
//     }
    
    //*********************************************************************************************************************************
    
      
    int dp[200][200]{}; // constraints are small enough that we can just set them to MAX
    int maxPath, n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(matrix, i, j, -1));            
        return maxPath;
    }
    int solve(vector<vector<int>>& mat, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
                                    solve(mat, i - 1, j, mat[i][j]),
                                    solve(mat, i, j + 1, mat[i][j]),
                                    solve(mat, i, j - 1, mat[i][j]) });       
    }
};