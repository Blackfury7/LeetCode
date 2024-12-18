class Solution {
public:
    vector<int>solve(vector<int>&nums){
        vector<int>nse(nums.size(),0);
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            nse[i]=st.empty()?0:nums[st.top()];
            st.push(i);
        }
        return nse;
    }
    
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>nse=solve(prices);
        vector<int>ans(prices.size());
        for(int i=0;i<prices.size();i++){
            ans[i]=prices[i]-nse[i];
            cout<<nse[i]<< " ";
        }
        return ans;
    }
};