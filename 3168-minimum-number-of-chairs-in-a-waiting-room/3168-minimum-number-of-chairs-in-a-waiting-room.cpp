class Solution {
public:
    int minimumChairs(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            if(s[i] == 'E'){
                cnt++;
            }
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};