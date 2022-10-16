class Solution {
public:
    int findMaxK(vector<int>& v) {
        unordered_map<int, int>m;
        int mx = -1;
        int n = v.size();
        for(int i = 0; i < n; i++) {
            m[v[i]] = 1;
            if(m[-v[i]] == 1) {
                mx = max(mx, max(v[i], -v[i]));
            }
        }
        return mx;
    }
};