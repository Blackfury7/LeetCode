class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int zero=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0) {
                zero++;
            }
            while(zero>1){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            ans=max(ans,right-left+1-zero);
        }
        return (ans==nums.size())?ans-1:ans;  
    }
};