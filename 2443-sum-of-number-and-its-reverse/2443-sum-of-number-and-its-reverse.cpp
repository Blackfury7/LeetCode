class Solution {
public:
    bool isrev(int i, int j) {
        int r = 0, rr = 0;
        int ii = i, jj = j;
        while(i) {
            r = r*10 + i%10;
            i/=10;
        }
        while(j) {
            rr = rr*10 + j%10;
            j/=10;
        }
        return r==jj or rr == ii;

    }
    bool sumOfNumberAndReverse(int num) {
        int n = num/2;
        for(int i=n; i >= 0; i--) {
            if(isrev(i, num - i)) {
                return true;
            }
        }
        return false;
    }
};