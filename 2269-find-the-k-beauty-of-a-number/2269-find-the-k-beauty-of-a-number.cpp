class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int f=0;
        int n = s.size();
        for(int i=0;i+k<=n;i++){
            string su = s.substr(i,k);
            int x = stoi(su);
            if(x && num % x ==0)f++;
        }
        return f;
    }
};