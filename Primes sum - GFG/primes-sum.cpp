//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void primeSieve(vector<bool>& primes, int n){
        primes[0] = primes[1] = false;
        for(int i = 2; i <= n; ++i){
            if(primes[i]){
                for(int j = 2*i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }
    }
    
    string isSumOfTwo(int target){
        int n = target;
        vector<bool> primes(target, true);
        primeSieve(primes, target);
        
        vector<int> v;
        for(int i = 0; i < n; ++i){
            if(primes[i]) v.push_back(i);
        }
        
        int s = 0, e = v.size()-1;
        
        while(s <= e){
            int sum1 = v[s] + v[e];
            int sum2 = v[s] + v[s];
            int sum3 = v[e] + v[e];
            
            if(sum1 == target || sum2 == target || sum3 == target) return "Yes";
            else if(sum1 < target){
                s += 1;
            }else{
                e -= 1;
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends