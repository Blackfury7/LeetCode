class Solution {
public:
    
    
    int minAnagramLength(string s) {
        int n = s.size();
        string a, b;
        int flag;
        
        for(int i = 1 ; i <= n; i++) {
            if(n % i == 0) {
                flag = 1;
                b="";
                for(int j=0; j < n/i; j++) {
                    a = s.substr(j*i, i);
                    sort(a.begin(), a.end());
                    if(b == "") {
                        b = a;
                    }
                    else{
                        if(b != a) {
                            flag = 0;
                            break;
                        }
                    } 
                }
                if(flag) return i;
            }
        }
        return n;
    }
};