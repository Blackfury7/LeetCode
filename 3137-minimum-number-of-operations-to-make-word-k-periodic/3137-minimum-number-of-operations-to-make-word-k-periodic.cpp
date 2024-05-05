class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        map<string, int> m;
        string s = "";
        for(int i =0 ; i<n; i++) {
            
            if(i && (i%k) ==0){
                m[s] += k;
                s="";
            }
            s.push_back(word[i]);
        }
        m[s] += k;
        int mx =0;
        for(auto& [i,j]:m){
            if(j > mx) mx=j;
        }
        return (n - mx)/k; 
            
    }
};