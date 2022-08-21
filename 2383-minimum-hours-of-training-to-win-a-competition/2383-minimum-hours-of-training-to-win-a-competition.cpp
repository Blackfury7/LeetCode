class Solution {
public:
    int minNumberOfHours(int en, int ex, vector<int>& energy, vector<int>& experience) {
        en -= accumulate(energy.begin(), energy.end(), 0)+1;
        int mn = INT_MAX;
        for(auto i:experience){
            ex -= i+1;
            mn = min(mn, ex);
            ex += 2*i+1;
        }
        return (en<0?abs(en):0) + (mn<0?abs(mn):0);
    }
};