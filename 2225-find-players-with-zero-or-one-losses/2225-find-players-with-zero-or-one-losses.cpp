class Solution {
public:
   vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loss;vector<vector<int>> ans;
        vector<int> a;
        vector<int> b;
        for(auto i:matches)
        {
            loss[i[1]]++;
        }
        for(auto i:matches)
        {
            if(!loss[i[0]]){
                a.push_back(i[0]);
                loss[i[0]]=10;
            }
        }
        
        for(auto i: loss) 
            if(i.second==1)
                b.push_back(i.first);
        

        sort(a.begin(),a.end());
        
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};