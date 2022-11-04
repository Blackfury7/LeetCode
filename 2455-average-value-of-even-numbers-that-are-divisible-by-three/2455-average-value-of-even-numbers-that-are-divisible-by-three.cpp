class Solution {
public:
    int averageValue(vector<int>& nums) {
        int f = 0; int sum = 0;
        for(auto &i: nums) {
            if((i&1 ) == 0 and i%3 == 0){
                sum += i;
                f++;
            }
        }
        if(f == 0) return 0;
        return sum/f;
    }
};