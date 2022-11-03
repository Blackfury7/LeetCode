class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto &w : words)
            ++m[w];
        int res = 0, center = 0, sz = 2;
        for (auto &[w, cnt] : m) {
            auto reversed = string(rbegin(w), rend(w));
            if (w == reversed) {
                res += 2 * (cnt / 2);
                center |= cnt % 2;
            }
            else {
                auto it = m.find(reversed);
                if (it != end(m))
                    res += min(cnt, it->second);
            }
        }
        return sz * res + (center ? sz : 0);
    }
};