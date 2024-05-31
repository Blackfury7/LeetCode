class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int> ans;
       for(int i = 0; i < size(nums) && size(ans) < 2; i++) 
           for(int j = 0; j < size(nums); j++) 
               if(i != j and nums[i] == nums[j]) break;
               else if(j == size(nums)-1) ans.push_back(nums[i]);
       return ans;
   }
};