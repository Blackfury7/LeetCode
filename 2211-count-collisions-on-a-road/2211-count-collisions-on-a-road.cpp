class Solution {
public:
    int countCollisions(string d) {
        int n = d.length();
        long r=0;
        for(int i=0;i<n;i++){
            if(i+1<n && d[i] == 'R'){
                if(d[i+1] == 'L'){
                    d[i+1] = 'S';
                    d[i] = 'S';
                    r+=2;
                    
                    int j=i-1;
                if(j>=0 && d[j] == 'R')
                {
                    r++;
                     d[j] = 'S';
                    j--;
                    while(j>=0 && d[j] == 'R')
                     {
                        d[j] = 'S';
                        r++; j--;
                     }
                    
                } 
                    i++;
    
                }
                else if(i+1<n && d[i+1] == 'S'){
                     
                    d[i] = 'S';
                    r+=1;
                    
                    int j=i-1;
                if(j>=0 && d[j] == 'R')
                {
                    r++;
                     d[j] = 'S';
                    j--;
                    while(j>=0 && d[j] == 'R')
                    {
                         d[j] = 'S';
                        r++; j--;
                    }
                    
                } 
                    i++;
         
                }   
            }
            else if(d[i] == 'L'){
                    if(i-1>=0 && d[i-1]=='S'){
                    r++;
                    d[i]='S';
                }
            }
        }
       return r;
        
    }
};