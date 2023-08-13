class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        bool prev1=1,prev2=1,prev3=1;
        
        for(int idx=n-1;idx>=0;idx--){
            bool two_ele=0,three_ele=0;
    
            //2 elements are equal
            if(idx+1<nums.size() && nums[idx]==nums[idx+1])
                two_ele = prev2;
        
            // 3 elements are equal or 3 consecutive elements are increasing 
            if(idx+2<nums.size() && 
              ((nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]) ||
              (nums[idx]+1==nums[idx+1] && nums[idx+1]+1==nums[idx+2])))
                three_ele = prev3;
            
            bool curr = two_ele || three_ele;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }    
        return prev1;
    }
};