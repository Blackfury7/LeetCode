class Solution {
public:
    
    // *************************** Sliding Window *************************** 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind = 0, min_s, sum = 0;
        int n = arr.size();
        for(int i = 0; i < k && i < n;i++)
            sum += abs(arr[i] - x);
        min_s = sum;
        
        for(int i = k; i < n; i++) {
            sum += abs(arr[i] - x);
            sum -= abs(arr[i-k] - x);
            if(sum < min_s){
                min_s = sum;
                ind = i-k+1;
            } 
        }
        
        
        return vector<int>(arr.begin() + ind, arr.begin() + ind + k);
        
    }
    
    // ***************************** Binary Search *****************************
    // vector<int> findClosestElements(vector<int>& A, int k, int x) {
    //     int left = 0, right = A.size() - k;
    //     while (left < right) {
    //         int mid = (left + right) / 2;
    //         if (x - A[mid] > A[mid + k] - x)
    //             left = mid + 1;
    //         else
    //             right = mid;
    //     }
    //     return vector<int>(A.begin() + left, A.begin() + left + k);
    // }
};