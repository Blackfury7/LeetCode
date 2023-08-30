class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            long long parts = 0;
            if(nums[i] % nums[i + 1] == 0) parts = nums[i] / nums[i + 1];
            else parts = nums[i] / nums[i + 1] + 1;
            ans += parts - 1;
            nums[i] = nums[i] / parts;
        }

        return ans;
    }
};