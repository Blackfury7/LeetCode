class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        ios_base::sync_with_stdio(0);
        cout.tie(NULL);
        cin.tie(NULL);
        unordered_map<int,int> m;
        // int n = nums.size();
         // sort(nums.begin(), nums.end());
        // for(int i=0; i<n-1; i++) {
        //     if(nums[i] == nums[i+1])return 1;
        // }
            
         for(auto i: nums) {
             if(m[i]) return 1;
             m[i]=1;
         }
        
        return 0;
    }
};