class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> ans(size(nums),1);
        for(int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++) {
            ans[i] *= pre;           
            pre *= nums[i];			
            ans[n-1-i] *= suf;
            suf *= nums[n-1-i];
        }
        return ans;
    }
};