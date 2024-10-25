class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        
        
        vector<string> ret;
        ret.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string root=ret[ret.size()-1]+"/";
            if(folder[i].substr(0,root.size())!=root){
                ret.push_back(folder[i]);
            }
        }
 
        return ret;
    }
};