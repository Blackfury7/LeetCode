class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),
             [](auto& a, auto& b){
                 return a[1] > b[1];
             }
            ); 
        int maxUnits = 0;
        for(auto& box : boxTypes) {
            if(truckSize <= 0) break;                   
            maxUnits += min(truckSize, box[0]) * box[1]; 
            truckSize -= box[0];
        }
        return maxUnits;
    }
};