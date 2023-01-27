class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>word_set(words.begin(),words.end());
        vector<string>ans;
        for(auto w:words){
            int n=w.size();
            vector<bool>dp(n+1,false);
            dp[0]=1;
            for(int i=0;i<n;i++){
                if(!dp[i])continue;
                for(int j=i+1;j<=n;j++){
                    if(j-i<n and word_set.count(w.substr(i,j-i)))
                    dp[j]=1;
                }
            }
            if(dp[n]==1)ans.push_back(w);
        }
       return ans;
    }
};