class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0;
            for (auto j = 0; j < nums.size(); ++j)
                if (i & (1 << j))
                    total ^= nums[j];
            res += total;
        }
        return res;
    }
};