class Solution {
public:
    vector<int> getMaximumXor(vector<int>& n, int maximumBit) {
        vector<int> res(n.size());
        int val = (1 << maximumBit) - 1;
        for (int i = 0; i < n.size(); ++i)
            res[n.size() - i - 1] = val ^= n[i];
        return res;
    }
};