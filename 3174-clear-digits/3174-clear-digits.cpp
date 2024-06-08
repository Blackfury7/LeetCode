class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        
        vector<int>v(n);
        int f = 0;
        for(int i = n-1; i >=0; i--){
            if(s[i] >= '0' and s[i]<='9'){
                f++;
                v[i]=1;
            }
            else{
                if(f>0){
                    v[i]=1;
                    f--;
                }
            }
        }
        string a="";
        for(int i = 0; i<n; i++){
            if(v[i] ==0) a.push_back(s[i]);
        }
        return a;
        
    }
};