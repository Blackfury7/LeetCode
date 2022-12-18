class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        st.push(0);
        vector<int>ans(n);
        for(int i=1;i<n;i++){
           
           if(!st.empty()&&temperatures[i]>temperatures[st.top()]){
             
               while(!st.empty()){
                 if(temperatures[i]>temperatures[st.top()]){
                     ans[st.top()]=i-st.top();
                     st.pop();  
                 }else{
                     break;
                 }
               }
               st.push(i);
           }
           else{
               st.push(i);
           }
           
        }
        while(!st.empty()){
               ans[st.top()]=0;
               st.pop();
           }
        return ans;
    }
};