class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans(2);
        ans[0] = celsius + 273.15;
        ans[1] = celsius * 1.8 + 32.0;
        
        return ans;
    }
};