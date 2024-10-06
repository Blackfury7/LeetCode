class Solution {
public:
    bool areSentencesSimilar(string s, string l) {
        if (l.size() == s.size())
            return s == l;
        if (l.size() < s.size())
            swap(s, l);
        int ss = -1, ls = s.size(), d = l.size() - s.size();
        for (int i = 0; i < s.size() && s[i] == l[i]; ++i)
            ss = s[i] == ' ' || l[i + 1] == ' ' ? i : ss;
        for (int i = s.size() - 1; i >= max(0, ss) && s[i] == l[d + i]; --i)
            ls = s[i] == ' ' || l[d + i - 1] == ' ' ? i : ls;
        return ss == s.size() - 1 || ls == 0 || ss == ls;
    }
};