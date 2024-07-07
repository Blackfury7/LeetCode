class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange)
        {
            int remainingBottles = numBottles%numExchange;
            numBottles /= numExchange;
            res += numBottles;
            numBottles += remainingBottles;
        }
        return res;
    }
};