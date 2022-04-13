class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto i: ops){
            if(i=="C")st.pop();
            else if(i=="D"){
                int k = st.top();
                // st.pop();
                st.push(k*2);
            }
            else if(i=="+"){
                int k=st.top();
                st.pop();
                int j = st.top();
                st.push(k);
                st.push(k+j);
            }
            else {
                cout<<i<<endl;
                st.push(stoi(i));
            }
        }
        int s=0;
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        return s;
    }
};