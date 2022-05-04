class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        int i,j; i=0;
        j=n-1;
        int f=0;
        while(i<j){
            int sum =nums[i] + nums[j];
            if(sum == k){
                f++;
                i++;
                j--;
            }
            else if(sum > k)
                j--;
            else
                i++;
        }
       return f;
    }
};