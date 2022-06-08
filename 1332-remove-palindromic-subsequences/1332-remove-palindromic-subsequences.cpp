class Solution {
public:
    int removePalindromeSub(string s) {
        // return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
        return 2 - equal(s.begin(), s.end(), s.rbegin()) - s.empty();
    }
};