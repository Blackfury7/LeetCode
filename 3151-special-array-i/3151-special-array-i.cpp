class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        
        for(int i = 1; i < n; i++) {
            if((nums[i]&1) == (nums[i-1]&1))
                return false;
        }
        return true;
    }
};