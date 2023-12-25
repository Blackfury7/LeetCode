class Solution {
    
    int solution(string &s, int i, int n,vector<int> &dp)
    {
        
        if(s[i] == '0')
            return 0;
        if(i >= n)
            return 1;
        if(dp[i] != -1)
            return dp[i];
        int left = solution(s,i+1,n,dp);
        int right = 0;
        
        if((i + 1) < n)
        {
            int num = (s[i] - '0') * 10  + (s[i+1] - '0') ;
            if(num >=1 && num <= 26)
            right = solution(s, i + 2, n,dp);
        }
        return dp[i] = left + right;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1,-1);
        return solution(s,0,n,dp);
    }
};