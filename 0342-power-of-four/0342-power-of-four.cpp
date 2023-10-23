class Solution {
public:
    /* Proof:
    (4^n - 1) % 3 == 0
    another proof:
    (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
    (2) among any 3 consecutive numbers, 
    there must be one that is a multiple of 3 among (2^n-1), (2^n), (2^n+1),
    one of them must be a multiple of 3, and (2^n) cannot be the one,
    therefore either (2^n-1) or (2^n+1) must be a multiple of 3, 
    and 4^n-1 must be a multiple of 3 as well.
    */
    
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};