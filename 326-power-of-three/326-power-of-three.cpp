class Solution {
public:
    bool isPowerOfThree(int n) {
        // recursive method
        // if(n==1) return true;
        // if(n<=0 || n%3)return false;
        // return isPowerOfThree(n/3);
        
        // iterative method
        if(!n) return false;
        while(n % 3 == 0) n /= 3;    
        return n == 1;
    }
};