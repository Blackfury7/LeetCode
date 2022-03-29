class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    
    }
    
//     int findDuplicate(vector<int>& nums) {
//     int n=nums.size()-1;
//     int low=1;
//     int high=n;
//     int mid;
//     while(low<high){
//         mid=(low+high)/2;
//         int count=0;
//         for(int num:nums){
//             if(num<=mid) count++;
//         }
//         if(count>mid) high=mid;
//         else low=mid+1; 
//     }
//     return low;
// }
    
    
};