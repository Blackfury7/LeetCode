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
    
    // bool validPalindrome(string s) {
    //     int n = s.length();
    //     int f=0;
    //     for(int i=0; i<n/2; i++){
    //         if(s[i]!=s[n-i-1])f++;
    //     }
    //     if( !f || f==1 && !(n&1))return true;
    //     else return false;
    // }
};