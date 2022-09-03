class Solution {
public:
    
    bool check(int n, int b) {
        string ans = "";
        while(n > 0 ){
            ans += to_string(n%b);
            n /= b;
        }
        string ans2 = ans;
        reverse(ans.begin(), ans.end());
        return ans == ans2;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i = 2 ; i <= n -2; i++) {
            if(check(n, i) == false) return false;
             
        }
        return true;
    }
};