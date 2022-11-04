class Solution {
public:
    static bool isVowel(char ch) {
        return
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string reverseVowels(string s) {
        string st;
        st.reserve(size(s));
        for (char ch : s)
            if (isVowel(ch)) st.push_back(ch);
        for (char& ch : s)
            if (isVowel(ch)) {
                ch = st.back();
                st.pop_back();
            }
        return s;
    }
};