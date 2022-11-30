class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //make a map and store the count
        unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        //use a set and store the count and compare the size of map and set
        unordered_set<int> s;
        for(auto x:mp){
            s.insert(x.second);
        }
        
        if(mp.size()==s.size()){
            return true;
        }else{
        return false;
        }
    }
};