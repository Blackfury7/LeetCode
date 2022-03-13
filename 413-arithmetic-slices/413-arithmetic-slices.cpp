class Solution {
public:
   int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n < 3) return 0;
        
        int prev = 0;
		if (A[2]-A[1] == A[1]-A[0]) prev = 1;
		int result = prev;
        
		for (int i = 3; i < n; ++i) {
            int cur = 0;
			if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                cur = prev + 1;
            }
            result += cur;
            prev = cur;
		}
        
		return result;
	}
};