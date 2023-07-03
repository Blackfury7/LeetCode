class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        if (s == goal) {
            unordered_set<char> uniqueChars;
            for (char ch : s) {
                if (uniqueChars.count(ch))
                    return true;
                uniqueChars.insert(ch);
            }
            return false;
        } else {
            vector<int> diffIndices;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i])
                    diffIndices.push_back(i);
                if (diffIndices.size() > 2)
                    return false;
            }

            if (diffIndices.size() != 2)
                return false;

            return (s[diffIndices[0]] == goal[diffIndices[1]]) && (s[diffIndices[1]] == goal[diffIndices[0]]);
        }
    }
};