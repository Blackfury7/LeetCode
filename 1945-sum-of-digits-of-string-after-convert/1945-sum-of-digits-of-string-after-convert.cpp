class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum = 0;
        for(char &ch : s) {
		    int val = ch-'a'+1;
		    sum += val < 10 ? val : (val%10 + val/10);
		}

        k -= 1;
        while(k-- && sum >= 10) 
            sum = sumDigits(sum);
        
        return sum;
    }
};