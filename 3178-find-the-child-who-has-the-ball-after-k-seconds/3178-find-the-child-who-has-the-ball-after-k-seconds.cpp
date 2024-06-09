class Solution {
public:
    int numberOfChild(int n, int k) {
        if(n==1) return 0;
        int f = k /(n-1);
        if(f&1){
            return(n - (k% (n-1)) - 1);
        }
        else {
            return ((k%(n-1)));
        }
    }
};