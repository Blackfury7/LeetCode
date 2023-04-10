class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '[' || s[i] =='{' || s[i]=='(') {
                st.push(s[i]);
            }
            if(st.empty())return false;
            
            if(s[i] == ']' || s[i] =='}' || s[i]==')') {
                c = st.top();
                if(s[i] == ']' && c!='[')return false;
                else if(s[i] =='}' && c!='{') return false;
                else if(s[i] ==')' && c!='(') return false;
                else
                    st.pop();
        }
    }
        
        return st.empty();
    }
};