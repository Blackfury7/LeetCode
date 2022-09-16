class Solution {
public:
    int mScore(vector<int> &nums,vector<int> &multipliers,int idx,int i,int j,int **dp){
        if(idx>=multipliers.size()){
            return 0;
        }
        if(dp[i][idx]!=INT_MIN){ 
            return dp[i][idx];
        }
        int ans1 = nums[i]*multipliers[idx] + mScore(nums,multipliers,idx+1,i+1,j,dp);
        int ans2 = nums[j]*multipliers[idx] + mScore(nums,multipliers,idx+1,i,j-1,dp);
        return dp[i][idx] = max(ans1,ans2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int **dp =new int*[multipliers.size()+1];
        for(int i=0;i<=multipliers.size();i++){
            dp[i] = new int[multipliers.size()+1];
            for(int j=0;j<=multipliers.size();j++){
               dp[i][j]=INT_MIN;
            }
        }
        return mScore(nums,multipliers,0,0,nums.size()-1,dp);
    }
};