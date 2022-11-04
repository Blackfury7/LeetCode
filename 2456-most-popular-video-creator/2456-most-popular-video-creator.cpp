class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        #define ll long long
        
        ll n = c.size();
        ll mx = 0;
        unordered_map<string, ll> m1, m2;
        for(ll i = 0; i < n; i++){
            m1[c[i]] += views[i];
   
        }
        mx = 0;
        vector<pair<int, string>> vp; 
        for(auto &i: m1) {
           vp.push_back({i.second, i.first});
        }
        
        sort(vp.begin(), vp.end(), greater<>());
        ll n1 = vp.size();
        unordered_set<string> st;
        
        for(ll i = 0; i < n1; i++) {
            if(i == 0)
            {
                st.insert(vp[0].second);
            }
            else if(vp[i-1].first == vp[i].first) {
                st.insert(vp[i].second);
            }
            else break;
        } 
        
        
        map<string, pair<string, ll>> m;
        for(ll i = 0; i < n; i++) {
            if(st.find(c[i]) != st.end()) {
                if(m.find(c[i]) != m.end()) {
                    if ( m[c[i]].second <= views[i] ) {
                        if(m[c[i]].second == views[i]) {
                            if(m[c[i]].first > ids[i]) {
                                m[c[i]].first = ids[i];
                            }
                        }
                        else {
                            m[c[i]].first = ids[i];
                            m[c[i]].second = views[i];
                        }
                        
                    }
                }
                else {
                    m[c[i]] = {ids[i], views[i]};
                }
            }
        }
        for(auto &i : m) {
            vector<string> v;
            v.push_back(i.first);
            v.push_back(i.second.first);
            ans.push_back(v);
        }
        return ans;
    }
};