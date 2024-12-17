class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        map<char, int, greater<char>> mySet;
        for(char &ch: s) mySet[ch]++;
        string res;
        while(!mySet.empty()) {
            int freq = mySet.begin()->second, c = 0;
            char ch = mySet.begin()->first;
            mySet.erase(mySet.begin());
            while(freq != 0) {
                c++;
                if(c > limit) {
                    if(mySet.empty()) return res;
                    res.push_back(mySet.begin()->first);
                    mySet.begin()->second--;
                    if(mySet.begin()->second == 0) mySet.erase(mySet.begin());
                    c = 1;
                }
                res.push_back(ch);
                freq--;
            }
        }
        return res;
    }
};