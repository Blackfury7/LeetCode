class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        short m[2][1000] = {};
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
                m[!(i % 2)][j + 1] = 
                                    a[i] == b[j] ? 
                                    m[i % 2][j] + 1 : 
                                    max(m[i % 2][j + 1], m[!(i % 2)][j]);
        return m[a.size() % 2][b.size()];
    }
};