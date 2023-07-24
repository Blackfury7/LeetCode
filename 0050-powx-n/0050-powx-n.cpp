class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        long long pow = abs(n);
        double ans = 1.0;
        while(pow>0){
            int last_bit = pow & 1;
            if(last_bit){
                ans = ans *x;
            }
            x = x*x;
            pow = pow>>1;
        }
        if(n<0) ans = 1/ans;
        return ans;
    }
};