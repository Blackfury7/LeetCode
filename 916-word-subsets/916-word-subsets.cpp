class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26), tmp(26);
        int i;
        for (string b: B) {
            tmp = counter(b);
            for(i = 0; i < 26; i++) 
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> res;
        for (string a: A) {
            tmp = counter(a);
            for(i = 0; i < 26; i++)
                if(tmp[i] < count[i])
                    break;
            if (i==26) res.push_back(a);
        }
        return res;
    }
    
    vector<int> counter(string& word){
        vector<int> count(26);
        for (char c : word) count[c - 'a']++;
        return count;
    }
    
    
    
    
    
    
    //*************************************************************************************
    
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         unordered_map<char,int>m1;
//         vector<string>v;
//         for(auto i:words2){
//             unordered_map<char, int> m3;
//             for(auto j: i)
//                ++m3[j];
//             for(auto j: m3)
//                 m1[j.first] = max(m1[j.first], j.second);
            
            
//             }
//             int flag;
//             for(auto i: words1){
//                 flag=1;
//                 unordered_map<char, int> m4;
//                 for(auto j: i)
//                     m4[j]++;
                
//                 for(auto j: m1){
//                     if(m4[j.first] < j.second)
//                     {
//                         flag=0; break;
//                     }
//                 }
//                 if(flag)v.push_back(i);
                
//             }
        
//         return v;
//     }
};