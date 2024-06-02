class Solution {
public:
    int countDays(int d, vector<vector<int>>& m) {
        vector<pair<int, int>>v;
        
        int n = m.size();
        int ans = 0;
        for(auto i:m){
            v.push_back({i[0],i[1]});
        }
        sort(v.begin(), v.end());
        n = v.size();
       
        int mx = v[0].second;
        for(int i = 1; i < n; i++) {
            
            if(v[i].first > mx) {
                ans += v[i].first - mx - 1;
                
            }
            mx = max(mx, v[i].second);
        }
        
        if(mx < d)
            ans += d - mx;
        ans += v[0].first - 1;
        
        
    
        return ans;
        
        
    }
};