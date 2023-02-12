class Solution {
public:
    #define ll long long
    long long countFairPairs(vector<int>& nums, int L, int U) {
        ll ans = 0;
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        for(int i = 0; i < n; i++) {
            int l = L - nums[i];
            int a = lower_bound(nums.begin() + i+1, nums.end(), l) - nums.begin();
            int b = upper_bound(nums.begin() + i+1, nums.end(), U - nums[i]) - nums.begin();
            b--;
            if(a == n or nums[b] > U-nums[i]) continue;
            int diff = b - a + 1;
            if(diff < 0)diff = 0;
            ans += diff;
        }
        return ans;
    }
};