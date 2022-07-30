class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>m1;
        vector<string>v;
        for(auto i:words2){
            unordered_map<char, int> m3;
            for(auto j: i)
               ++m3[j];
            for(auto j: m3)
                m1[j.first] = max(m1[j.first], j.second);
            
            
            }
            int flag;
            for(auto i: words1){
                flag=1;
                unordered_map<char, int> m4;
                for(auto j: i)
                    m4[j]++;
                
                for(auto j: m1){
                    if(m4[j.first] < j.second)
                    {
                        flag=0; break;
                    }
                }
                if(flag)v.push_back(i);
                
            }
        
        return v;
    }
};