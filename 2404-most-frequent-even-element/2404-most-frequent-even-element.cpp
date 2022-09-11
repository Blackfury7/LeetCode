class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        for(auto &i:nums){
            if(!(i&1))
            m[i]++;
        }
        int mx = 0, ans = -1;
        for(auto [i,j]:m){
            if(j > mx){
                mx = j;
                ans = i;
            }
        }
        return ans;
        
            
    }
};