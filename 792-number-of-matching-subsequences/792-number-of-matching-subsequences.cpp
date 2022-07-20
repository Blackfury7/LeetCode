class Solution {
public:
   // int numMatchingSubseq(string S, vector<string>& words) {
   //      vector<const char*> waiting[128];
   //      for (auto &w : words)
   //          waiting[w[0]].push_back(w.c_str());
   //      for (char c : S) {
   //          auto advance = waiting[c];
   //          waiting[c].clear();
   //          for (auto it : advance)
   //              waiting[*++it].push_back(it);
   //      }
   //      return waiting[0].size();
   //  }
    //*********************************************************************
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> mappings(26);
        for(int i = 0; i< size(s); i++) mappings[s[i] - 'a'].push_back(i);
        for(auto &word: words) {
            bool found = true;
            // i = index in word | prev = index in s match for word[i - 1]
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = mappings[word[i] - 'a'];
                auto it = upper_bound(begin(v), end(v), prev); // check if current character exists in s with index > prev
                if(it == end(v)) found = false;
                else prev = *it;
            }
            ans += found;
        }
        return ans;
        
    }
};