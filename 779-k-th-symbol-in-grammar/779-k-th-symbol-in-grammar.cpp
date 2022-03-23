class Solution {
public:
    int kthGrammar(int n, int k) {
       k--;
        int cnt = 0;
        while (k) {
            cnt += k&1;
            k >>= 1;
        }
        return cnt&1;
    }
};