class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> groups = groupSizes;
        vector<vector<int>> res;
        for(int i = 0; i<n;i++){
            int curr = groups[i];
            if(groups[i] != -1 && groups[i] == curr){
                vector<int> ans;
                int j = 0;
                int k = curr;
                while(j<n && k){
                    if(groups[j]==curr){
                    ans.push_back(j);
                    groups[j] = -1;
                    k--;
                    }
                    j++;
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};