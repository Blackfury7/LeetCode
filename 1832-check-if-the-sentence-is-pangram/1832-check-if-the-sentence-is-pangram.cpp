class Solution {
public:
    bool checkIfPangram(string sen) {
        // unordered_set<char>s;
        // for(auto &i : sen) s.insert(i);
        // return s.size() == 26;
        return set<char>(sen.begin(), sen.end()).size() == 26;
    }
};