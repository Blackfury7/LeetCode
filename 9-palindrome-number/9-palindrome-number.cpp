class Solution {
public:
    bool isPalindrome(int x) {
        long long rev,c;
        if(x<0)
            return false;
        c=x;
        rev=0;
        while(c){
            rev=rev*10+c%10;
            c/=10;
            
        }
        return (rev==x);
        
    }
};