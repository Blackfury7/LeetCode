class Solution {
public:
       /* Approach-1: We first calculate longest common sequence in both the strings using dp.
       Then, subtract twice of lcs from sum of the length of two strings.
    formula: M+N - 2*LCS
    where- M-length of word1, N-length of word2

    TC: O(MxN), SC: O(MxN)
    */
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n ; j++){
                if(i==0 || j==0) continue;
                
                else if(word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m + n - 2*dp[m][n];
    }
};