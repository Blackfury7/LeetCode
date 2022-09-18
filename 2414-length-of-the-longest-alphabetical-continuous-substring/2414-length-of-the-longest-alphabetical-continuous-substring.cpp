class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int f = 1, mx = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] + 1 == s[i+1] )
                f++;
            else{
                mx = max(f, mx);
                f = 1;
            }
        }
        return max(mx, f);
    }
};