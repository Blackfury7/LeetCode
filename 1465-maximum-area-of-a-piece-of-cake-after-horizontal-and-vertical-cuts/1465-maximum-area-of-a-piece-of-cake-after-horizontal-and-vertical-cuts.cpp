class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int n = hc.size();
        int m = vc.size();
        
        int hor = max(hc[0], h - hc[n-1]);
        int ver = max( vc[0], w - vc[m-1]);
        for(int i = 1; i<n ;i++) {
            hor = max(hor, hc[i] - hc[i-1]);
        }
        for(int i = 1; i<m; i++){
            ver = max(ver, vc[i] - vc[i-1]);
        }
        return (int)(((long long)hor * ver) % 1000000007);
    }
};