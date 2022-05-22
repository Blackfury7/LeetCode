class Solution {
public:
    int countSubstrings(string& s) {
       return tabulation(s);
    }
    
    // 1. recursive
    // Time: O(n ^ 3)
    int recursive(string& s) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += helper(s, i, j);
            }
        }
        return count;
    }
    
    // return 1 if s[i..j] is palindromic, 0 otherwise.
    int helper(string& s, int i, int j) {
        if (i >= j) return 1;
        return s[i] == s[j] ? helper(s, i+1, j-1) : 0;
    }
    
    
    // 2. memoization
    // Time: O(n ^ 2)
    // space: O(n ^ 2)
    int memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += solve(mem, s, i, j);
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if (mem[i][j] >= 0) return mem[i][j];
        return mem[i][j] = s[i] == s[j] ? solve(mem, s, i+1, j-1) : 0;
    }
    
    
    // 3. tabulation
    // time: O(n ^ 2)
    // space: O(n ^ 2)
    int tabulation(string& s) {
        vector<vector<int>> tab(s.size(), vector<int>(s.size()));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if (i == j) {
                    tab[i][j] = 1;
                } else if (i + 1 == j) {
                    tab[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    tab[i][j] = s[i] == s[j] ? tab[i+1][j-1] : 0;
                }
                count += tab[i][j];
            }
        }
        return count;
    }
};