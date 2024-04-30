class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024);
        long long res = 0, cur = 0;
        count[0] = 1L;
        for (char& c: word) {
            cur ^= 1 << (c - 'a');
            res += count[cur]++;
            for (int i = 0; i < 10; ++i)
                res += count[cur ^ (1 << i)];
        }
        return res;
    }
};