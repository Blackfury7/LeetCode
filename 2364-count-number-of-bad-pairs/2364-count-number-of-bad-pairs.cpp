class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = n * (n - 1) / 2;
        map<int, long long> m;
        for (int i = 0; i < n; i += 1) m[nums[i] - i] += 1;
        for (auto [x, y] : m)
            ans -= y * (y - 1) / 2;
        return ans;
    }
};