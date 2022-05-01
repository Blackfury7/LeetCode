class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a,b;
        for(auto i:s){
            if(i=='#'){
               if(!a.empty())a.pop();
        }
            else 
                a.push(i);
    }
        for(auto i:t){
            if(i=='#'){
               if(!b.empty())b.pop();
        }
            else 
               b.push(i);
    }
        int n=a.size();
        if(n == b.size()){
            while(!a.empty()){
                char c = a.top();
                a.pop();
                char d = b.top(); 
                b.pop();
                
                if(c != d)return false;
            }
        }
        else return false;
        
        return true;
    }
};