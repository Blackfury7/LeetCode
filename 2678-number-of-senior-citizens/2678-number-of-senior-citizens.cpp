class Solution {
public:
    static int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string& s: details)
            cnt+=stoi(s.substr(11,2))>60;
        return cnt;
    }
};