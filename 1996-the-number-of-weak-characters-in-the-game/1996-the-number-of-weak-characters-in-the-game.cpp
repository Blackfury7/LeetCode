class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& ps) {
    int res = 0, max_def = INT_MIN;    
    sort(begin(ps), end(ps), [](const auto &a, const auto &b) { 
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
    for (const auto &p : ps) {
        res += p[1] < max_def;
        max_def = max(max_def, p[1]);
    }
    return res;
}
};