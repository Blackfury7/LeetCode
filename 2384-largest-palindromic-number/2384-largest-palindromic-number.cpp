class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int>m;
        for(auto i:num) m[i]++;
        string ans="", single="";
        for(auto [x,y]:m){
            for(int i = 0; i<y/2;  ans += x, i++);
            if(y&1)single = x;
        }
        int i=0, n = ans.size();
        for( i =n-1 ;i>=0 && ans[i] =='0';i--);
           ans = ans.substr(0, i + 1);
        string ans1 = ans;
        reverse(ans.begin(), ans.end());
        ans =  ans + single + ans1;
        return ans.size()==0?"0":ans;
    }
};