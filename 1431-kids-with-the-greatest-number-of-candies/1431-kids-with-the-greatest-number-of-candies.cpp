class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n=extraCandies;
        vector<int>a;
        a=candies;
        sort(a.begin(),a.end());
        int y=candies.size();
        int x=a[y-1];
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+n>=x){
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        return ans;
    }
};