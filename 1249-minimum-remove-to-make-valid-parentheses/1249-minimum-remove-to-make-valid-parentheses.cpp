class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        // Approach store the indices & check for validation.
        // If validated just pop, if not validated remove that i th from the string
        stack<int> st;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(s[i] == ')') {
                if(!st.empty() && s[st.top()] == '(') 
                    st.pop();
                else {
                    s.erase(i,1);
                    i--;
                }
                  
            }
            else if(s[i] == '(') st.push(i);
        }
        
        while(!st.empty()) {
            s.erase(st.top(), 1);
            st.pop();
        }
        
        return s;
    }
};