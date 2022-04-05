class Solution {
public:
    int countOdds(int low, int high) {
        // return (high - low) / 2 + ((high - low)&1 || low&1 && high&1) ;
        return (high - low) / 2 + (low&1 || high&1) ;
    }
};