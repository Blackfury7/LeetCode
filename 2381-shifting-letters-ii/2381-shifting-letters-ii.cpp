class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>v(n + 1);
        for(auto shift : shifts) {
            int x = shift[2]>0?1:-1;
            v[shift[0]] += x;
            v[shift[1] + 1] -= x;
        }
        for(int i = 1; i < n; i++) v[i] += v[i - 1]; // prefix sum
        for(int i=0; i<n; i++) s[i] = ((s[i] + (v[i]%26) - 'a' + 26)%26)+'a';
        return s;
    }
};