class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> set;
        for(int i=0; i + k <= n ; i++) {
            string sub = s.substr(i,k);
            set.insert(sub);
            
        }
        return set.size() == 1<<k;
    }
};