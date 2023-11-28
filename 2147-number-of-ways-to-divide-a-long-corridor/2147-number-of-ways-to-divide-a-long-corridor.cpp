class Solution {
public:
     int numberOfWays(string s) {
        long res = 1, j = 0, k = 0, mod = 1e9 + 7;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'S') {
                if (++k > 2 && k % 2 == 1)
                    res = res * (i - j) % mod;
                j = i;
            }
        }
        return k % 2 == 0 && k > 0 ? res : 0;
    }
};