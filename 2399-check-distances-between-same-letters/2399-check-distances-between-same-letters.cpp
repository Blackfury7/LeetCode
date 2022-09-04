class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int i = 0; i<26;i++) {
            char c = 'a' + i;
            if(s.find(c) == string::npos) continue;
//             if(d[i] == 0) {
                
                
//             }
            int k,j;
            for(k=0;k<n;k++)if(s1[k] == c)break;
            for(j=n-1;j>=0;j--)if(s1[j] ==c)break;
            // int a = s1.find(c);
            // int b = n - 1 - s.find(c);
            cout<<c<<" i j"<<i<<" "<<j<<endl;
           if(j-k-1 != d[i]) return false;
            
            
        } 
        return true;
    }
};