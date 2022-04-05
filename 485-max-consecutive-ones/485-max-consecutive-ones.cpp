class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int mx=0;
        while(i<n && j<n){
            if(nums[j]==1)j++;
            else{
                mx = max(mx, j-i);
                i=++j;
            }
        }
        return max(mx, j-i);
    }
};