class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        int N = A.size();
        if(N==0) return {};
        vector<string> ans;
        long long start;
        for(int i=0;i<N;i++)
        {
            if(i == 0) {
                start = A[i];
            }
            else if( ((long long)A[i] - (long long)A[i-1]) != 1) {
                string a = "";
                if(start == A[i-1]) a = to_string(start);
                else a = to_string(start) + "->" + to_string(A[i-1]);
                ans.push_back(a);
                start = A[i];
            }
        }
        if(start == A[N-1]) ans.push_back(to_string(start));
        else ans.push_back(to_string(start) + "->" + to_string(A[N-1]));
        return ans;
    }
};