class Solution {
public:
     vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(n);
        dp[n-1] = {nums[n-1]};

        int ans_size = 1, ans_index = n-1;
        for(int i=n-2; i>=0; i--){
            int sub_ans_size = 0, sub_ans_index = -1;
            for(int j=i+1; j<n; j++){
                if(nums[j]%nums[i] == 0 && dp[j].size() > sub_ans_size){
                    sub_ans_size = dp[j].size();
                    sub_ans_index = j;
                }
            }
            dp[i] = {nums[i]};
            if(sub_ans_index != -1) dp[i].insert(dp[i].end(), dp[sub_ans_index].begin(), dp[sub_ans_index].end());
            if(ans_size < dp[i].size()){ 
                ans_size = dp[i].size();
                ans_index = i;
            }
        }
        
        return dp[ans_index];
    }
};