class Solution {
public:
    // int numberOfWeakCharacters(vector<vector<int>>& ps) {
    //     int res = 0, max_def = INT_MIN;    
    //     sort(begin(ps), end(ps), [](const auto &a, const auto &b) { 
    //         return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
    //     for (const auto &p : ps) {
    //         res += p[1] < max_def;
    //         max_def = max(max_def, p[1]);
    //     }
    //     return res;
    // }
    
    
    
    //TC: O(N)
    int numberOfWeakCharacters(vector<vector<int>>& ps) {
        int max_d[100002] = {}, res = 0;
        for (auto &p : ps)
            max_d[p[0]] = max(max_d[p[0]], p[1]);
        for (int i = 100000; i > 0; --i)
            max_d[i - 1] = max(max_d[i - 1], max_d[i]);
        for (auto &p : ps)
            res += max_d[p[0] + 1] > p[1];
        return res;
    }
};