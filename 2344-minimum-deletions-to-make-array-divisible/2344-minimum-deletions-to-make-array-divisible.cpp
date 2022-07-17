class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc=numsDivide[0];
        for(auto i:numsDivide){
            gc = __gcd(gc, i);
        }
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int i=0;
        for(;i<n;i++){
            if(gc % nums[i] == 0)
                break;
        }
        return (i>=n?-1:i);
    }
};