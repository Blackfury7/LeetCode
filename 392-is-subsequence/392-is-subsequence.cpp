class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t1,s1,flag = 1;
        t1=t.length();s1=s.length();
        int indxS=0;
        for(int i=0;i<t1;i++){
            if(t[i] == s[indxS])indxS++;
            
        }
        if(indxS == s1)return 1;
        return 0;
        
    }
};