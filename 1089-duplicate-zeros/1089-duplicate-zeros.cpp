class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        //*****************************************************************************
        // insert() takes O(n). so time complexity for this is O(n^2)
        // int n = arr.size();
        // for(int i = 0; i<n; i++){
        //     if(arr[i] == 0) {
        //         arr.insert(arr.begin() + ++i, 0); 
        //         arr.pop_back();
        //     }
        // }
        
        
        //*****************************************************************************
        //Though this C++ code is not intuitive, but the method is pretty cool.

        // 1. count 0s, create a fake array, len + len(0s)
        // 2. two pointer, i starts from len-1, j starts from len+len(0s)-1, 
         // why? we need to avoid value overwrite, we have to loop reversely.
        // 3. assign i value to j, when i is 0, assign 0 twice
        // 4. add a condition, only perform the copy when j is under the actual array
        
        int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                arr[j] = arr[i];
            if (arr[i] == 0 && --j < n)
                arr[j] = 0;
        }
        
        //*****************************************************************************
        
        
    }
};