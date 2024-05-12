class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        vector<int> v(k);        
        int n = e.size();        
        for(int i = 0; i < n; i++) {
            if(v[i%k] < 0){
                v[i%k] = 0;
            }            
            v[i%k] += e[i];
        }
        return *max_element(v.begin(), v.end());        
    }
};