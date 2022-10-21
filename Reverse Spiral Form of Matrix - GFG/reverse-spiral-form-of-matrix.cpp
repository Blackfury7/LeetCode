//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int>ans;

        

        int firstRow = 0;

        int lastRow = R-1;

        int firstCol = 0;

        int lastCol = C-1;

        

        int total = R*C;

        

        int count = 0;

        

        while(count<total)

        {

            for(int index=firstCol;index<=lastCol && count<total;index++)

            {

                ans.push_back(a[firstRow][index]);

                count++;

            }

            

            firstRow++;

            

            for(int index=firstRow;index<=lastRow && count<total;index++)

            {

                ans.push_back(a[index][lastCol]);

                count++;

            }

            

            lastCol--;

            

            for(int index=lastCol;index>=firstCol && count<total;index--)

            {

                ans.push_back(a[lastRow][index]);

                count++;

            }

            

            lastRow--;

            

            for(int index=lastRow;index>=firstRow && count<total;index--)

            {

                ans.push_back(a[index][firstCol]);

                count++;

            }

            

            firstCol++;

        }

        

        reverse(ans.begin(),ans.end());

        

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends