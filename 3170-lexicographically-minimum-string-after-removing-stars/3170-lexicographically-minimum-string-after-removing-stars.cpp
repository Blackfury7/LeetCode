class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int>v(n+1);
        
        set<pair<int , int>>st;
        
        for(int i = 0 ;i < n; i++) {
            if(s[i] != '*'){
                st.insert({s[i] - 'a', -i});
                continue;
            }
            v[i] = 1;
            if(st.empty()) continue;
            v[-st.begin()->second] = 1;
            
            st.erase(st.begin());
            
        }
        string ans = "";
        for(int i = 0 ; i < n; i++){
            if(v[i] == 0) ans.push_back(s[i]);
        }
        
        return ans;
        
    }
};