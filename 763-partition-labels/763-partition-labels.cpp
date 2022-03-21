class Solution {
public:
    vector<int> partitionLabels(string s) {
     vector<int> res, pos(26,0);
        for(int i = 0; i < s.size(); i++) pos[s[i]-'a'] = i;
        for(int i = 0, idx = INT_MIN, last_i =0; i< s.size(); i++) {
            idx = max(idx, pos[s[i]-'a']);
            if( idx == i) res.push_back(i - exchange(last_i, i+1) + 1);
        }
        return res;
    }
};