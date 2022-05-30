class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> maxlen;
        for (string word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
        }
        int result = 0;
        for (auto a : maxlen)
            for (auto b : maxlen)
                if (!(a.first & b.first))
                    result = max(result, a.second * b.second);
        return result;
    }
};