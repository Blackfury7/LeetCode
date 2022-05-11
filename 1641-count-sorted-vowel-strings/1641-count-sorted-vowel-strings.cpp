// class Solution {
// public:
//     int countVowelStrings(int n) {
//         int ans = 0;
//         for (int j=1; j<=(n+1); j++) {
//             int sum = 0;
//             for (int i=1; i<=j; i++) {
//                 sum += i;
//                 ans += sum;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;
        
        while (--n){
            e += a;
            i += e;
            o += i;
            u += o;         
        }
        return a + e + i + o + u;
    }
};