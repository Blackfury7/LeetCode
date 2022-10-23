class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int n = nums.size();
        vector<int> odd1, odd2, even1, even2;
        
        for(auto &i : nums) {
            if(i&1) {
                odd1.push_back(i);
            }
            else even1.push_back(i);
        }
        for(auto &i: target) {
            if(i&1 ) odd2.push_back(i);
            else even2.push_back(i);
        }
        sort(odd1.begin(), odd1.end());
         sort(odd2.begin(), odd2.end());
         sort(even1.begin(), even1.end());
         sort(even2.begin(), even2.end());
        
        int o1 = odd1.size();
        for(int i = 0; i < o1; i++) {
            if(odd1[i] < odd2[i]) {
                ans += odd2[i] - odd1[i];
            }
        }
        int e1 = even1.size();
        for(int i = 0; i < e1; i++) {
            if(even1[i] < even2[i]) {
                ans += even2[i] - even1[i];
            }
        }
        return ans/2;
    } 
};