class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32);
        long res = 0;
        for (int i = 0 ; i < 32 ; ++i) {
            int sum = 0;   
            for (auto num : nums) {
                int lastDigit = (num >> i) & 1; // Getting last bit
                sum += lastDigit; // Summation of ith bit in each number
            }
            sum = sum % 3; // To get bit not having mutliple of 3
            res = res + (sum << i); // Building the answer from each bit
        }
        return res;
    }
};