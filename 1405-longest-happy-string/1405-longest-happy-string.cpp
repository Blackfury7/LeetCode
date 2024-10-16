class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int total=a+b+c;
        int currA=0, currB=0, currC=0;
        string res = "";
        while(total--){
            
            if((a>=b && a>=c && currA!=2) || (a>0 && (currB==2|| currC==2))){
                res+='a'; 
                a--;
                currA++;
                currB=currC=0;
            }
            else if((b>=a && b>=c && currB!=2) || (b>0 && (currA==2|| currC==2))){
                res+='b';
                b--;
                currB++;
                currA=currC=0;
            }
            else if((c>=a && c>=b && currC!=2) || (c>0 && (currA==2|| currB==2))){
                res+='c';
                c--;
                currC++;
                currA=currB=0;
            }
        }
        return res;
    }
};