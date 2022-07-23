class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        long long n=nums.size();
        long long f=0;
        for(auto i:nums){
            if(i==0){
                f++;
            }
            else{
                sum += (f*(f+1))>>1;
                f=0;
            }
        }
        if(f)sum += (f*(f+1))>>1;
        return sum;
    }
};