class Solution {
public:
     int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        if(n < 2) return 0;
        vector<int> dp(5001, 0);
        map<int, pair<int,int> > sits = {};
       
        sits[0] = {0,0};

        for(int i = 0; i < n; i++){

            vector<pair<int,int> > vec;
            for(auto kv: sits){
                vec.push_back(kv.second);
            }
            for(auto it : vec){
                int diff = abs(it.first+rods[i] - it.second);
                int value = max(it.first+rods[i], it.second);
                dp[diff] = max(dp[diff], value);
                if(dp[diff] == value){ sits[diff] = make_pair(it.first+rods[i], it.second);}
                diff = abs(it.second+rods[i] - it.first);
                value = max(it.second+rods[i], it.first);
                dp[diff] = max(dp[diff], value);
                if(dp[diff] == value){ sits[diff] = make_pair(it.second+rods[i], it.first);}

            }
        }
        return dp[0];
    }
};