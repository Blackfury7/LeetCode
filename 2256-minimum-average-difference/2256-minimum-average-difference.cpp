class Solution {
public:
    
    int minimumAverageDifference(vector<int>& nums) {
         int n= nums.size();
        if(n==1)return 0;
        long long sum = 0;
        for(auto i:nums)sum += i;
        // if(sum ==0)return 0;
        long long avg=INT_MAX;
       
        int ind = 0;
        long long sum2=0;
        for(int i=0;i<n;i++){
            sum2 += nums[i];
            int y = n - i - 1;
            y = y?y:1;
            int x = abs(int(sum2/(i+1)) - int((sum - sum2)/(y)));
            if(x < avg){
                avg = x;
                ind = i;
            }
        }
        return ind;
    }
};