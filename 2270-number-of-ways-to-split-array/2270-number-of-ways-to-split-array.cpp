class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int f=0;
        long s=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            s += nums[i];
        }
        long r=0;
        int i=n-1;
        for( i=n-1;i>0; i--){
            s -= nums[i];
            r += nums[i];
            if(s >= r)f++;
        }
        return f;
    }
};