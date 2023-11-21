class Solution {
public:
    int countNicePairs(vector<int>& A) {
        int res = 0, mod = 1e9 + 7;
        unordered_map<int, int> count;
        for (int& a : A)
            res = (res + count[a - rev(a)]++) % mod;
        return res;
    }
    int rev(int a) {
        int b = 0;
        while (a > 0) {
            b = b * 10 + (a % 10);
            a /= 10;
        }
        return b;
    }
};