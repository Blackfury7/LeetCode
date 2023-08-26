class Solution {
public:
    int solve(int i, int prev, vector<vector<int>>& pairs, vector<vector<int>>&dp){
        if(i>=pairs.size()){
            return 0;
        }

        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
            take=1+solve(i+1, i, pairs, dp);
        }
        int ntake=solve(i+1, prev, pairs, dp);
        if(prev!=-1){
            dp[i][prev]=max(take, ntake);
        }
        return max(take, ntake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>>dp(1001, vector<int>(1001, -1));
        return solve(0, -1, pairs, dp);
    }
};