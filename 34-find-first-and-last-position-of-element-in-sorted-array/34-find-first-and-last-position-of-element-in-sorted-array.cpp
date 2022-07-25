class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(), nums.end(), target)) return {-1,-1};
        int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int b = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {a,b-1};
    }
};