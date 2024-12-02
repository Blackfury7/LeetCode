class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 1, n = searchWord.size();
        stringstream s(sentence);
        string word;
        while (s >> word) {
            if (word.substr(0, n) == searchWord)
                return i;
            i++;
        }
        return -1;
    }
};