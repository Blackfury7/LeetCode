class Solution {
public:
    int maxProfit(vector<int>& arr) {

        int maxPro=INT_MIN,mn=INT_MAX;
        
        for(int i=0;i<arr.size();i++)
        { 
            mn=min(mn,arr[i]);
            maxPro=max(maxPro,arr[i]-mn);
         
        }
        return maxPro;
    }
};