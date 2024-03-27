class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int ans=0;
        int start=0,end=0,product=1;
        int n=nums.size();
        for(end; end<n; end++){
            product*=nums[end];
            while(product>=k){
                product/=nums[start++];
            }
            if(product<k)
                ans+=(end-start)+1;
        }
        return ans;
    }
};