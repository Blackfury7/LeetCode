class Solution {
public:
    int solve(vector<int>& cookies, int i, int n, int k, vector<int>& helper){
        if(i == n){
            int mx = INT_MIN;
            for(int j=0; j<k; j++){
                mx = max(mx, helper[j]);
            }
            return mx;
        }
        int answer = INT_MAX;
        for(int j=0; j<k; j++){
            helper[j] += cookies[i];
            answer = min(answer, solve(cookies, i+1, n, k, helper));
            helper[j] -= cookies[i];
        }
        return answer;

    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> helper(k , 0);
        return solve(cookies, 0, cookies.size(), k, helper);
    }
};