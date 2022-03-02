class Solution {
public:
    bool isSubsequence(string t, string s) {
        int t1,s1,flag = 1;
        t1=t.length();s1=s.length();
        if(t1>s1)return 0;
        int j=0;
        for(int i=0;i<s1 && j<t1;i++){
            if(t[j] == s[i]){
                j++;
            }
            if(s1-i < t1 - j)
                return 0;
        }
        if(j==t1)return 1;
        return 0;
    }
};