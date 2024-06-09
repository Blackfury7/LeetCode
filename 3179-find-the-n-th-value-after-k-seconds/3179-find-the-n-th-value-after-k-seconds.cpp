class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int mod = 1e9 + 7;
        vector<int> v(n+1, 1);
        v[0]=0;
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++) {
                v[j] = (v[j]%mod + v[j-1]%mod)%mod;
            }
        }
        return v[n];
    }
};