class Solution {
public:
    int minFlips(int a, int b, int c) {
       int ans = 0;
        for (int i = 0; i <= 31; i++)
        {
            int bit1 = (a & (1 << i));
            int bit2 = (b & (1 << i));

            if (c & (1 << i))
            {
                if (!bit1 && !bit2)
                    ans += 1;
            }
            else
            {
                if (bit1)
                    ans += 1;
                if (bit2)
                    ans += 1;
            }
        }
        return ans; 
    }
};