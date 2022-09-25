class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int f = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == mx and nums[i+1] == mx) {
                f++;
            }
            else {
                ans = max(ans, f+1);
                f=0;
            }
        }
        return max(ans, f+1);
    }
};