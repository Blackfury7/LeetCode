class Solution {
public:
    string customSortString(string order, string str) 
    {
        unordered_map<char,int> mp;
        int j=0;
        for(auto i:order)
            mp[i]=j++;
        sort(str.begin(),str.end(),[&](const char &a,const char &b){
            return mp[a]<mp[b];
        });
        return str;
    }
};