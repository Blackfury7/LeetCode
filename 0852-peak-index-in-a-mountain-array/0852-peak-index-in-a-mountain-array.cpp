class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid-1>=0 && mid+1<n && arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(mid-1<0 && mid+1<n && arr[mid]<arr[mid+1]){
                return mid+1;
            }else if(arr[mid-1]<arr[mid]&& arr[mid]<arr[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return 0;
    }
};