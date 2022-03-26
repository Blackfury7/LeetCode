class Solution {
public:
    
    int binS(vector<int>& nums, int l, int r, int t) {
        int mid = (l+r)/2;
        
        if(l>r)return -1;
        if(nums[mid]==t){
            return mid;    
        }
        else if(nums[mid] < t){
          return  binS(nums, mid+1, r,t);
            
        }
        else {
           return binS(nums, l, mid-1,t);
        }
        // return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return binS(nums,0,nums.size()-1,target);
    }
};