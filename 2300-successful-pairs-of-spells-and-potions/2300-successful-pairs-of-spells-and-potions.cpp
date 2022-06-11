class Solution {
public:
    #define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n,m;
        n = spells.size();
        
        m = potions.size();
        vector<int> p(potions.begin(), potions.end());
        m=p.size();
        vector<int>v;
        int f=0;

        sort(p.begin(), p.end());
        for(int i=0;i<n;i++){
            f=0;
            ll x = success/spells[i] + (success%spells[i]?1:0);
            auto aa = lower_bound(p.begin(), p.end(), x);
            if(aa != p.end()){
                v.push_back(m-(aa-p.begin()));
            }
            else v.push_back(0);
        }
        return v;
    }
};