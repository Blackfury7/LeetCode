class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      
        
        int n = nums.size(),k,l;
        for(k=n-2; k>=0; k--) {
            if(nums[k] < nums[k+1])
                break;
            }
            if(k<0) {
                reverse(nums.begin(), nums.end());
            }else {
                for(l = n-1; l > k; l--) {
                    if(nums[l] > nums[k]) break;
                } 
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
        }
        
        
          // next_permutation(begin(nums), end(nums));
        
        //****************************************************
        
        // int i = nums.size() - 1, k = i;
        // while (i > 0 && nums[i-1] >= nums[i])
        //     i--;
        // for (int j=i; j<k; j++, k--)
        //     swap(nums[j], nums[k]);
        // if (i > 0) {
        //     k = i--;
        //     while (nums[k] <= nums[i])
        //         k++;
        //     swap(nums[i], nums[k]);
        // }
        //****************************************************
        
    }
};