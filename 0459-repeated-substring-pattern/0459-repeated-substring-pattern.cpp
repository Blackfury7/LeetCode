class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int len=1;len<=n/2;len++)
        {
            if(s.size()%len==0){
                string sub=s.substr(0,len);
                string v="";
                for(int j=0;j<s.size()/len;j++)
                {
                    v+=sub;
                }
                if(v==s)
                return true;
            }

            
        }
        return false;
    }
};