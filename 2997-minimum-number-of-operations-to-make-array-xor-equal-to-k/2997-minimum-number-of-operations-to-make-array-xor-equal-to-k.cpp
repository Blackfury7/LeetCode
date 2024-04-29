class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        for (int a : A)
            k ^= a;
        return __builtin_popcount(k);
    }
};