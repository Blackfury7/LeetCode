class Solution {
public:
    int rec(vector<int>&nums,int i,int j,int chance)
    {
        if(i>j)
        return 0;
        if(chance==0)
        return max(nums[i]+rec(nums,i+1,j,1),nums[j]+rec(nums,i,j-1,1));
        else
        return min(rec(nums,i+1,j,0),rec(nums,i,j-1,0));
    }
    int rec1(vector<int>&nums,int i,int j,int chance,vector<vector<vector<int>>>&dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j][chance]!=0)
        return dp[i][j][chance];
        if(chance==0)
        return dp[i][j][chance]=max(nums[i]+rec1(nums,i+1,j,1,dp),
        nums[j]+rec1(nums,i,j-1,1,dp));
        else
        return dp[i][j][chance]=min(rec1(nums,i+1,j,0,dp),
        rec1(nums,i,j-1,0,dp));
    }
        bool PredictTheWinner(vector<int>& nums) {
            int n=nums.size();
            long long one=0;
            long long two=0;
            for(int i=0;i<n;i++)
            two+=nums[i];
            // one=rec(nums,0,n-1,0);
            // two=two-one;
            // return (one>=two);

            // memoization
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
            one=rec1(nums,0,n-1,0,dp);
            two=two-one;
            return (one>=two);
        }
};