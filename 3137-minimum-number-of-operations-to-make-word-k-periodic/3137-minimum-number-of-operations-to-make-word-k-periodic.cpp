class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        map<string, int> m;
        string s = "";
        for(int i =0 ; i<n; i+=k) {
            string a = word.substr(i,k);
                m[a] += k;
        }
        
        int mx =0;
        for(auto& [i,j]:m)
            mx = max(mx, j);
        
        return (n - mx)/k; 
            
    }
};