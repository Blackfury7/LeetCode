class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool alpha[123] = {};
      
        for (char c: allowed) alpha[c] = true;
        for (string word: words) {
            for (char c: word) if (!alpha[c]) {
                res--;
                break;
            }
        }
        return res;
  
    }
};