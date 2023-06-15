//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int N = s.size();
        int l = -1, r = -1;
        int len = 0;
        for(int i = 0; i < N; i++) {
            // odd length
            int d = 0;     // d -> distance from mid
            while( i-d >= 0 && i+d < N && s[i-d] == s[i+d]) {
                int nlen = 2*d + 1;
                if(nlen > len) {
                    len = nlen;
                    l = i - d;
                    r = i + d;
                }
                d++;
            } 
            // even length
            d = 0;
            while( i-d+1 >= 0 && i+d < N && s[i-d+1] == s[i+d]) {
                int nlen = 2*d;
                if(nlen > len) {
                    len = nlen;
                    l = i - d+1;
                    r = i + d;
                }
                d++;
            } 
        }
        return s.substr(l, len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends