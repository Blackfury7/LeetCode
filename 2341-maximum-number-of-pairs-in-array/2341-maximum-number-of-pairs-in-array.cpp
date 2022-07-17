class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int n =nums.size();
        for(auto i:nums){
            m[i]++;
            
        }
        int f =0;
        for(auto i:m){
            f += (i.second & 1);
        }
        return {(n- f)/2, f};
    }
};