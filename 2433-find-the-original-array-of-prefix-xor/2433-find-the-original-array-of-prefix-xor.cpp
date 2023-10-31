class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = 0;
        int n = pref.size();
        for(int i = 0; i < n; i++) {
            
            pref[i] ^= x;
            x ^= pref[i];
        }
        return pref;
    }
};