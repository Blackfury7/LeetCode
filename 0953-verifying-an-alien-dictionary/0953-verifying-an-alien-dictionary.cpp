class Solution {
public:
     bool Helper(string &w1,string &w2,unordered_map<char,int> &mp)
     {
         int n = w1.length();
         int m = w2.length();

         for(int i=0;i<min(n,m);i++)
         {
             if(mp[w1[i]] < mp[w2[i]])
             {
                 return true;
             }
             else if(mp[w1[i]] > mp[w2[i]]){
                 return false;
             }
         }

         if(m>=n)return true;
         return false;

     }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++)
        {
            mp[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            if(!Helper(words[i],words[i+1],mp))
            {
                return false;
            }
        }
        return true;
    }
};