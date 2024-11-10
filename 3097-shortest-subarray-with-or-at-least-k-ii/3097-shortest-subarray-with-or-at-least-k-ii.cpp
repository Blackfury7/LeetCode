class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cnt[30] = {}, cur = 0, res = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            for (int b = 0; b < 30; ++b)
                if ((1 << b) & nums[i])
                    if (++cnt[b] == 1)
                        cur += (1 << b);
            while (cur >= k && j <= i) {
                res = min(res, i - j + 1);
                for (int b = 0; b < 30; ++b)
                    if ((1 << b) & nums[j])
                        if (--cnt[b] == 0)
                            cur -= (1 << b);
                ++j;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};