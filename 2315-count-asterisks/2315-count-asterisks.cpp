class Solution {
public:
    int countAsterisks(string s) {
        int n = s.size();
        int f = 0, ans=0;
        for(int i=0;i<n;i++){
            if(s[i] == '|')f++;
            else if(!(f&1) && s[i]=='*' ){
                ans++;                
            }
        }
        return ans;
    }
};