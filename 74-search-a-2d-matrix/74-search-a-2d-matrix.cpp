class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0, r=n-1,mid;
        while(l<=r){
            mid = (l+r)/2;            
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]) break;
            else if(target < matrix[mid][0]) r = mid -1;  
            else l = mid +1;
        }
        
        l = 0; r = m-1;
        int mid2;
        while(l<=r){
            mid2 = (l+r)/2;
            if(target == matrix[mid][mid2])return true;
            else if(target < matrix[mid][mid2])r=mid2-1;
            else l=mid2+1;
        }
        return false;
    }
};