class Solution {
public:
    int hammingWeight(uint32_t num) {
        return __builtin_popcount(num);
        
        // int n=0;
        // while(num){
        //     n++;
        //     num &=num-1;
        // }
        // return n;
        
    }
};