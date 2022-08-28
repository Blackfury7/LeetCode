class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>preSum(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++) 
            preSum[i] += preSum[i-1];
        
        vector<int>v;
        for(auto &q:queries){
            int a = upper_bound(preSum.begin(), preSum.end(), q) - preSum.begin();
            v.push_back(a);
        }
        return v;
        
    }
};