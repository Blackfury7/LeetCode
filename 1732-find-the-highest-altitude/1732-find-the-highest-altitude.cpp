class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int val = 0;
        int maxalt = 0;
        for(int i=0;i<gain.size();i++){
          val = val + gain[i];
           maxalt = max(val,maxalt);
        }
        return maxalt;
    }
};