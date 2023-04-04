class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans = 0;
        for(auto &i: s) {
            if(st.find(i) == st.end()) {
                st.insert(i);
            }  
            else {
                ans++;
                st.clear();
                st.insert(i);
            }
        }
        if(st.size() > 0) ans++;
        return ans;
    }
};