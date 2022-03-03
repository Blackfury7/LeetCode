class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag=0,i,n = s.length();
        for( i=n-1;i>-1;i--){
            
            if(s[i]==' ' && flag)
                break;
            if(s[i]!=' ' && s[i]!='\t' && s[i]!='\n')
                flag=1;
            if(!flag)
                n--;
        };
        return (n-i-1);
    }
};