class Solution {
public:
    int helper(string& s1, string& s2, int si1, int si2, vector<vector<int>>& dp){
        int n1 = s1.size(), n2 = s2.size();
        if (n1 == si1){
            int fin = 0;
            for(int i=si2; i<n2; i++){
                fin += s2[i];
            }
            return fin;
        }
        if (n2 == si2){
            int fin = 0;
            for(int i=si1; i<n1; i++){
                fin += s1[i];
            }
            return fin;
        }
        if (dp[si1][si2] != -1){
            return dp[si1][si2];
        }
        if (s1[si1] != s2[si2]){
            int op1 = helper(s1, s2, si1+1, si2, dp) + s1[si1];
            int op2 = helper(s1, s2, si1, si2+1, dp) + s2[si2];
            dp[si1][si2] = min(op1, op2);
        }else{
            dp[si1][si2] = helper(s1, s2, si1+1, si2+1, dp); 
        }
        return dp[si1][si2];
    }
public:
    int minimumDeleteSum(string& s1, string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return helper(s1, s2, 0, 0, dp);
    }
};