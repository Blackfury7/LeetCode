class Solution {
public:
    unordered_set<string> st;
    int maxUniqueSplit(string &s, int p = 0) {
        if (p == s.size())
            return 0;
        int res = -1;
        for (int sz = 1; p + sz <= s.size(); ++sz) {
            auto it = st.insert(s.substr(p, sz));
            if (it.second) {
                int n_res = maxUniqueSplit(s, p + sz);
                if (n_res != -1)
                    res = max(res, 1 + n_res);
                st.erase(it.first);
            }    
        }
        return res;
    }
};