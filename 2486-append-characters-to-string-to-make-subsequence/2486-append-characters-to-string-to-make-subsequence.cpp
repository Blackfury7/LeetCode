class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int j = 0;
        for (int i = 0; i < s.size() && j < t.size(); i++)
            j += s[i] == t[j];
        return t.size() - j;
    }
};