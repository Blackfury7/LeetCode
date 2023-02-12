class Solution {
public:
    #define ll long long
    long long findTheArrayConcVal(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        for(int i = 0, j = n-1; i < n and i<=j ; i++, j--) {
            ans += (ll)(nums[j]);
            if(i!=j){
                ll r = 0;
                while(nums[j] > 0){
                    nums[j]/=10;
                    r++;
                    nums[i]*=10;
                }
                ans += (ll)(nums[i]);
            }
        }
        return ans;
    }
};