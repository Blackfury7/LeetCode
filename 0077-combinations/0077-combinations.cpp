class Solution {
public:
    void solve(int start,int k, vector<int>&v, int n , vector<vector<int>>&ans){
    
        if(k==0) {
            ans.push_back(v);
            return;

        }
        if(start==n+1)  return;


        v.push_back(start);
        solve(start+1,k-1,v,n,ans);
        v.pop_back();
        solve(start+1,k,v,n,ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(1,k,v,n,ans);
        return ans;

    }
};