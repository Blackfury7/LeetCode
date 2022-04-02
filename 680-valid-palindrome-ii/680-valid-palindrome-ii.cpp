class Solution {
public:
    
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return validPalin(s, left, right - 1) || validPalin(s, left + 1, right);
            left++;
            right--;
        }
        return true;
    }
    
    bool validPalin(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

};