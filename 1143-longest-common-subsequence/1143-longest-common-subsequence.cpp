class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int i=0;i<text1.size()+1;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<text2.size()+1;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<text1.size()+1;i++){
            for(int j=1;j<text2.size()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
    
    
    
    // int longestCommonSubsequence(string &a, string &b) {
    //     short m[2][1000] = {};
    //     for (int i = 0; i < a.size(); ++i)
    //         for (int j = 0; j < b.size(); ++j)
    //             m[!(i % 2)][j + 1] = a[i] == b[j] ? m[i % 2][j] + 1 : max(m[i % 2][j + 1], m[!(i % 2)][j]);
    //     return m[a.size() % 2][b.size()];
    // }
};