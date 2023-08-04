class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n = s.length();
      vector<bool> dp(n+1 ,false );
      dp[0] = true;
      for(int i = 1 ; i<= n ; ++i){
         for( const string& word : wordDict){
             int len = word.length();
             if(i>= len && s.substr(i-len , len) == word){
                 dp[i] = dp[i] || dp[i-len];
             }
         }
      }
      return dp[n];
    }
};