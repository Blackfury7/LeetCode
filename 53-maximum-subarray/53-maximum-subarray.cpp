class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum,sum;
        max_sum=sum=nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(sum < 0) sum = nums[i];
            else
                sum += nums[i];
            max_sum = max(max_sum, sum);
        }
        
      return max_sum;  
    }
};