class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char, int>a,b;
        for(auto i:r)a[i]++;
        for(auto i:m)b[i]++;
        
        for(auto [x,y]: a)
            if(b[x] < y)return false;
        return true;
    }
};