//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        int mod=1e8;
        vector<int> v(N+1,0);
        v[1]=1;
        v[2]=2;
        for(int i=3;i<=N;i++)
        {
            v[i]=(v[i-1]+v[i-2])%mod;
        }
        return v[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends