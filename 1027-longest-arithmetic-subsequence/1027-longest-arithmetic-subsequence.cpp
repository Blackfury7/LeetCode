class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
         int ans=INT_MIN;
        //vector<int,unordered_map<int,int>>dp(nums.size());
        unordered_map<int,int>dp[nums.size()];
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]=dp[j][diff]+1;
                }
                else
                 dp[i][diff]=2;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
   
    }
};