class Solution {
public:
    string smallestNumber(string p) {
         int n = p.size();
        string s = "123456789";
        do {
            bool ok = 1;
            for(int i = 0; (i < n) & ok ; i++)
                if((s[i] < s[i+1]) ^ (p[i] == 'I')) ok = 0;
            if(ok) break;
        } while(next_permutation(s.begin(), s.end()));
        
        return s.substr(0, n + 1);
    }
};