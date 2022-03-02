class Solution {
public:
    int fib(int n) {
        int ar[n+2];
        ar[1]=1;ar[0]=0;
        for(int i=2;i<=n;i++){
            ar[i] = ar[i-1] + ar[i-2];
        }
       return ar[n];
    }
};