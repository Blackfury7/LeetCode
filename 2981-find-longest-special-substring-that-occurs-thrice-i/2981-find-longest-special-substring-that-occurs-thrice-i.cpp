class Solution {
public:
    bool check(string s){
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]) return 0;
        }
        return 1;
    }
    int maximumLength(string s) {
        unordered_map<string ,int> m;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                m[s.substr(i,j-i+1)]++;
            }
        }
        int ans=0;
        for(auto x : m){
            if(x.second>=3&&check(x.first)){
                ans=max(ans,(int)x.first.size());
            }
        }
        return (!ans)?-1:ans;
    }
};