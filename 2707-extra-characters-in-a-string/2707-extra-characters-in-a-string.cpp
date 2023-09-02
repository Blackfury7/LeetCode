class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size()+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1 ;i <= s.size(); i++){
            dp[i] = dp[i-1] + 1;
            for(auto word:dictionary){
                int wsize = word.size();
                if(word[wsize-1] == s[i-1] && i-wsize >= 0){
                    if(word == s.substr(i-wsize, wsize)){
                        dp[i] = min(dp[i], dp[i-wsize]);
                    }
                }
            }
        }
        return dp[s.size()];
    }
};