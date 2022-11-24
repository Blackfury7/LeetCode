//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int> inc(n), dec(n);
	    
	   inc[0] = 1, dec[n-1] = 1;
	   
	   for(int i = 1; i < n; i++){
	       int mx = 0;
	       for(int j = 0; j < i; j++){
	           if(nums[i] > nums[j])
	           mx = max(mx, inc[j]);
	       }
	       
	       inc[i] = mx+1;
	   }
	   
	   for(int j = n-1; j >= 0; j--){
	       int mx = 0;
	       for(int k = n-1; k > j; k--){
	           if(nums[j] > nums[k]){
	               mx = max(mx, dec[k]);
	           }
	       }
	       dec[j] = mx+1;
	       
	   }
	   
	   
	   int ans = 0;
	   for(int i = 0; i < n; i++){
	       ans = max(ans, inc[i]+dec[i]-1);
	   }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends