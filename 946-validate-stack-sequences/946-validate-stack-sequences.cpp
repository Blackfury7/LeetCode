class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        bool res=0;
        int n1=pushed.size();int n2=popped.size();
        for(int i=0,j=0; j<n2;){
            if(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            else if(i<n1){
                st.push(pushed[i]);
                i++;
            }
            else {
                return st.empty();
            }
        }
        return st.empty();
    }
};