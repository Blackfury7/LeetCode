class Solution {
public:
    int climbStairs(int n) {
        int ar[n+2];
        ar[0] = 1; ar[1] = 2;
        for(int i=2;i<n;i++){
            ar[i] = ar[i-1] +  ar[i-2];
        }
        
        return ar[n-1];
    }
};