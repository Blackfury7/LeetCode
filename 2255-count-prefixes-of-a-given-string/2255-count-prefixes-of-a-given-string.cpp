class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n=s.length();
        int f=0;
        for(auto i:words){
            int n1 = i.length();
            if(n1<=n){
                bool flag= 1;
               for(int k = 0;k<n1;k++){
                   if(i[k] != s[k]){
                       flag=0; 
                       break;
                   }
               }
                if(flag)
                    f++;
            }
        }
        return f;
    }
};