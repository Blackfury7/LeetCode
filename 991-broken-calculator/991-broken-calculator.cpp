class Solution {
public:
    int brokenCalc(int start, int target) {
        if(start>= target)
            return start - target;
        return 1 + (!(target&1)? brokenCalc(start, target/2) : brokenCalc(start, target + 1));
    }
};