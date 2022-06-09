
// Two pointer approach
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i=0,j=nums.size()-1;
//         while(i<j){
//             int sum = nums[i] + nums[j];
//             if(sum==target) return {i+1,j+1};
//             else if(sum>target) j--;
//             else i++;
//         }
//         return {}; // not found
//     }
// };


// Binary search approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        for(int i=0;i<N-1;i++){
            int lo = i+1;
            int hi = N;
            while(lo<hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]==target-nums[i]) return {i+1,mid+1}; // returning the indices
                else if(nums[mid]>=target-nums[i]) hi=mid;
                else lo = mid+1;
            }
            if(lo!=nums.size() && nums[lo]==target-nums[i]) return {i+1,lo+1};
        }
        return {}; // Target not found
    }
};