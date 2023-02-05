class Solution {
public:
    
    bool com(unordered_map<char,int>a,unordered_map<char,int>b){
        for(auto i:a){
            auto x = char(i.first);
            if(b.find(i.first)!=b.end()){
                if(b[i.first] != i.second)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> a,b;
        vector<int>in;
        for(auto i: p){
            if(a.find(i)!=a.end()){
                a[i]++;
            }
            else{
                a[i]=1;
            }
        }
        
        int n = s.length();
        int n1 = p.length();
        for(int i=0;i<n;i++){
             if(b.find(s[i])!=b.end()){
                b[s[i]]++;
            }
            else{
                b[s[i]]=1;
            }
            if(i+1>=n1){
                if(com(a,b)){
                    cout<<"hello";
                    in.push_back(i-n1+1);
                }
                
                b[s[i+1-n1]]--;
            }
        }
       return in; 
    }
};