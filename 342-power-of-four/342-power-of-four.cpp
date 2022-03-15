class Solution {
public:
        bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
        }
        
        
//         if(n==1)
//             return true;
//         if(n&1)
//             return false;
//         for(int i=2;i<=log2(n)+1;i+=2){
//             if( (n&(1<<i)) && !(n&(n-1)))
//                 return true;
                
//         }
//         return false;
//     }
};