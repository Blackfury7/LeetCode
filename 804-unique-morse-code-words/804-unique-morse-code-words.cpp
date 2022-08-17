class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string>word_set;
        string ar[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word: words) {
            string coded_word = "";
            for(auto ch: word) {
                coded_word += ar[ch - 'a'];
            }
            word_set.insert(coded_word);
        }
        return word_set.size();
    }
};