class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v (nums.begin(), nums.end());
        sort(v.begin(), v.end());
        
        int a,b,f;a=b=0;
        f=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] != v[i]){
                if(!f){
                    a=i;
                    f=1;
                }
                b=i;
            }
        }
        if(!f)return 0;
        return b - a +1;
    }
};