//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> sol;
		if(N == 1)
		{
		    sol.push_back(A[0][0]);
		    return sol;
		}
		
		for(int k = 0; k < N; k++)
		{
		    int i = 0;
		    int j = k;
		    
		    while(j > -1)
		    {
		        sol.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		for(int k = 1; k < N; k++)
		{
		    int i = k;
		    int j = N-1;
		    
		    while(i < N)
		    {
		        sol.push_back(A[i][j]);
		        i++;
		        j--;
		    }
		}
		
		
		return sol;
		
	}


};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends