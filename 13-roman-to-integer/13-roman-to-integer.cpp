class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> t = {{'I',1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000}};
        int sum = t[s.back()];
        for (int i = s.length() - 2; i>=0; --i){
            if(t[s[i]] < t[s[i+1]]){
                sum -= t[s[i]];
            }
            else{
                sum += t[s[i]];
            }
        }
        
        
        return sum;
    }
};