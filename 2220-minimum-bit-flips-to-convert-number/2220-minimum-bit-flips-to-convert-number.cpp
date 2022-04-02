class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long x = start ^ goal;
        int f=0;
       while(x){
           if(x&1)f++;
           x= x>>1;
       }
        return f;
    }
};