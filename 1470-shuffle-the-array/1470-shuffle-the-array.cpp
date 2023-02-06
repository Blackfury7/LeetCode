class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len = nums.size();
        
		// to store the pair of numbers in right half of the original array
        for(int i = n; i < nums.size(); i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }
        
        int index = 0;
		// to retrive values from the pair of numbers and placing those retrieved value at their desired position
        for(int i = n; i < nums.size(); i++, index += 2) {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }
        
        return nums;
        
    }
};