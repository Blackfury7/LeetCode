class Solution {
public:
    int bestClosingTime(string cus) {
        int n = cus.size();
        vector<vector<int>> v(n+1, vector<int>(2));
        int ty=0, tn=0;
        for(int i = 0; i < n; i++) {
            v[i+1][0] = v[i][0] + (cus[i] =='Y');
            v[i+1][1] = v[i][1] + (cus[i] == 'N');
        }
        ty = v[n][0];
        tn = v[n][1];
        int ans = INT_MAX;
        int ind = 0;
        for(int i = 0; i <= n; i++) {
            int d = v[i][1] + (ty - v[i][0]);
            if(d < ans) {
                ans = d;
                ind = i;
            }
        }
        return ind;
    }
};