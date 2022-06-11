class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        string s = "!@#$%^&*()-+";
        
        vector<int>v(5);
        v[0]=1;
        int n=pass.length();
        if(n<8)return false;
        for(int i=0;i<n;i++){
            if(i+1<n && pass[i]==pass[i+1])return false;
            if(!v[1]){
            for(int j=0;j<12;j++){
                if(pass[i] == s[j]){
                    v[1]=1;
                    break;
                }
            }
            }
            if(pass[i] >= 'a' && pass[i]<='z')v[2]=1;
            else if(pass[i] >= 'A' && pass[i]<='Z')v[3]=1;
            else if(pass[i] >= '0' && pass[i]<='9')v[4]=1;
        }
        for(auto i:v){
            if(!i)return false;
        }
        return true;
    }
};