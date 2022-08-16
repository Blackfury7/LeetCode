class Solution {
public:
    int firstUniqChar(string s) {
        int map[26]={0};
        for(auto i:s)map[i - 'a']++;
        int n = s.size();
        int i;
        for(i = 0; i < n; i++) 
            if(map[s[i] - 'a'] == 1)return i;
        
        return -1;
    }
};