class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        
        int n = nums.size();
        for(int i=1 ; i<n-1; i++){
            int j=i-1, k=i+1;
            if(nums[i] == nums[k])
                while(++k<n && nums[i] == nums[k]);
            if(k<n){
            if(nums[i]>nums[k] && nums[i]>nums[j])ans++;
            else if(nums[i]<nums[k] && nums[i]<nums[j])ans++;
            }
               i=k-1;
            }
    return ans;
    }
};