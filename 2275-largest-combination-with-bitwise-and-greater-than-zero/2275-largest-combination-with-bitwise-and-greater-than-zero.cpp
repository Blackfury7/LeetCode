class Solution {
public:
    int largestCombination(vector<int>& A) {
        int res = 0, cur = 0;
        for (int i = 1; i <= 10000000; i <<= 1) {
            cur = 0;
            for (int& a : A)
                if (a & i)
                    cur++;
            res = max(res, cur);
        }
        return res;        
    }
};