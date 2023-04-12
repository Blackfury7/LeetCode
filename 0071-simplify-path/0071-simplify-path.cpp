class Solution {
public:
    string simplifyPath(string s) {
        vector<string> v;
        s +="/";
        string temp;
        temp="";
        int count,flag=1;
        int n = s.length();
        
        // splitting string with del="/" or multiple of "/". 
        for(int i=0;i<n;i++) {
            
            if(s[i] == '/') {
                if(flag)flag=0;
                else
                v.push_back(temp);
                
                temp="";
                while(s[++i]=='/');
            }
            temp += s[i];
        }
        // now vector v contains all the words of the path
        
         stack<string> st;
        
        for(auto i: v) {
            count=0;flag=1;
            if(i != "." && i!="..")
                st.push(i);
            
            else {
                
    //****  code for if multiple period was allowed to go back in directory   *****************
                // for(auto j: i) {
                //     if(j == '.')count++;
                //     else {flag=0;break;}
                // }
                // if(flag)
                //     while(--count && !st.empty())st.pop();
    //*****************************************************************************************            
                if(i==".."&& !st.empty())st.pop();
                
            }
     
            
        }
        
        string s1 ="";
        while(st.size()){
            s1 = "/"+st.top()+s1; 
            st.pop();
        }
        if(s1.length()==0)return "/";
        return s1;
    }
};