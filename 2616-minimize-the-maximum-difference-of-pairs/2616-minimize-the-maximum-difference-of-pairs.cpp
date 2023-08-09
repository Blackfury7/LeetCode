class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::adjacent_difference(nums.begin(), nums.end(), nums.begin(), 
                                 [](int i, int j) { return abs(i - j); });
        int min = 0;
        int max = *std::max_element(nums.cbegin() + 1, nums.cend());
        while (min < max) {
            int mid = min + (max - min) / 2;
            int count {0};
            for (int i = 1; i < n; ++i) {
                if (nums[i] <= mid) {
                    if (++count == p) break;
                    ++i;
                }
            }
            if (count == p) max = mid;
            else min = mid + 1;
        }
        return min;
    }
};