class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {

        long long f=0,a=0,b=0;
        int n = text.length();
        for(int i =0; i<n ;i++) {
            if(text[i] == pattern[0]) a++;
            else if(text[i] == pattern[1]) b++;
        }
        
        if(pattern[0] == pattern[1]){
            if(a==0)return 0;
            else return (a)*(a+1)/2;
        }    
        
        f = max(a,b);

        for(int i =0; i<n ;i++) {
            if(text[i] == pattern[0]) f += b;
            else if(text[i] == pattern[1]) b--;    
        }
            
            return f;
            
    }
};