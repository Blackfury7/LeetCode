class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
            if(digits[n]==9){
                digits[n] = 0;
                while(--n>=0){
                    if(digits[n]==9)
                        digits[n]=0;
                    else {
                    digits[n]+=1; break;
                    }
                   }
                    if(n<0 && digits[0]==0 )digits.insert(digits.begin(), 1); 
                } 
                else 
                digits[n]+=1; 
        return digits;
    }
};