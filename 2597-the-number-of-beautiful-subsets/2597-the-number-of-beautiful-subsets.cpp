class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>mp;
        for (auto el : nums){
            mp[el%k].push_back(el);
        }
        
        int ans = 1;
        for(auto& [mod_cal, v] : mp){
            sort(v.begin(), v.end());
            map<int, int> mp2;
            for (auto el : v) mp2[el]++;
            
            int prev_el = INT_MIN, 
            prevNotTaken = 1, 
            prevTaken = 0, 
            nowNotTaken = 0, 
            nowTaken = 0;
            for(auto& [el, freq] : mp2){
                int poss_subsets = pow(2, freq) - 1;
                if(prev_el+k == el){
                    nowNotTaken = prevNotTaken + prevTaken;
                    nowTaken = prevNotTaken * poss_subsets;
                }
                else{
                    nowNotTaken = prevNotTaken + prevTaken;
                    nowTaken = (prevNotTaken + prevTaken) * poss_subsets;
                }
                
                prevNotTaken = nowNotTaken;
                prevTaken = nowTaken;
                prev_el = el;
            }
            ans *= (nowNotTaken + nowTaken);                 
        }
        return ans - 1;
    }
};