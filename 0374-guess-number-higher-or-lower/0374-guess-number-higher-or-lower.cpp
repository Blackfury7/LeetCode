/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n, long s = 1) {
        while (s <= n)
        {
            int x = (n + s) / 2;        
            int g = guess(x);
            if (g == 0) return x;
            if (g < 0)  n = x - 1;
            if (g > 0)  s = x + 1;
        }
        return -1;   
        
    }
};