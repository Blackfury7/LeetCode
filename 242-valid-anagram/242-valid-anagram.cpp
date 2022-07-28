class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>a,b;
        for(auto i:s)a[i]++;
        for(auto i:t)b[i]++;
        
        if(a.size() != b.size())return false;
        for(auto i:a){
            if(b[i.first] != i.second) return false;
        }
        return true;
    }
};