class Solution {
public:
    #define ll long long int
    long long maximumPoints(vector<int>& ene, int ce) {
        ll ans = 0;
        ll sum = 0;
        int n = ene.size();
        int mn = ene[0];
        for(int i = 0; i < n;i++) {
            sum += ene[i];
            mn = min(ene[i], mn);
        }
        if(ce < mn) {
            return 0LL;
        }
        sum+=ce-mn;
        ans = sum / mn;
        return ans;
    }
};