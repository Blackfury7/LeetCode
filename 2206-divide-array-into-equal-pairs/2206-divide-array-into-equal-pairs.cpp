class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long x=0;
        for(int i=0;i<n-1; i+=2){
            // x ^= nums[i];
            if(nums[i] != nums[i+1])return false;
        }
        // if(!x)
        //     return true;
        // else return false;
        return true;
    }
};