class Solution {
public:
    
    int maximumEnergy(vector<int>& e, int k) {
        vector<int> res(k, 0);
        int n = e.size();
        int ans = -(1<<30);
        for(int i = n - 1; i >= 0; i--){
            res[i % k] += e[i];
            ans = max(ans, res[i % k]);
        }
        return ans;
    }
    
    // int maximumEnergy(vector<int>& e, int k) {
    //     vector<int> v(k);        
    //     int n = e.size();        
    //     for(int i = 0; i < n; i++) {
    //         if(v[i%k] < 0){
    //             v[i%k] = 0;
    //         }            
    //         v[i%k] += e[i];
    //     }
    //     return *max_element(v.begin(), v.end());        
    // }
};