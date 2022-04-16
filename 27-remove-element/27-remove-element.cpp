class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};