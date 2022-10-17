class Solution {
public:
    bool checkIfPangram(string sen) {
        // 
        // unordered_set<char>s;
        // for(auto &i : sen) s.insert(i);
        // return s.size() == 26;
        
        // one liner code
        // return set<char>(sen.begin(), sen.end()).size() == 26;
        
        // 3rd logic
        int seen = 0;
        for( char c : sen) {
            int ci = c - 'a' ;
            seen = seen | (1 << ci);
        }
        return seen == ((1 << 26) - 1);
    }
};