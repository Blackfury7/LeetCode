//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long lcmTriplets(long long N) {
        if(N == 2 || N == 1)  return N;
        if(N%2) return N*(N-1)*(N-2);
        long long a = (N*(N-1))/(__gcd(N, N-1));
        long long b = ((N-1)*(N-2))/(__gcd(N-1, N-2));
        return max(((a*(N-3))/(__gcd(a, N-3))), ((b*(N-3))/(__gcd(b, N-3))));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends