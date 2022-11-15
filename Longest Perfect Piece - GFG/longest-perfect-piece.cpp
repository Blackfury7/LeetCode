//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
        int a, b;
        int i = 0, j = 0, res = 0;
        while (i < n) {
            a = arr[i];
            b = -1;
            j = i + 1;
            while(j < n) {
                if (b == -1 && abs(arr[j] - a) == 1)
                    b = arr[j++];
                else if (arr[j] == a || arr[j] == b)
                    j++;
                else
                    break;
            }
            // cout << i << " " << j << endl;
            res = max(res, j - i);
            if (j >= n)
                break;
            i = j;
            if (abs(arr[j] - arr[j - 1]) == 1) {
                i = j - 1;
                a = arr[j];
                b = arr[i];
                while (arr[i] == b)
                    i--;
                i++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends