class Solution {
public:
    double soupServings(int n) {
       if (pow(.99,n/25)<=1e-5) return 1; // .99 larger than requered
        // if (n>800) return 1;
        bool c = false;
        if (n%25) c=true;
        n /=25;

        vector<double> m1(n+1,0);
        vector<double> m2(n+1,0);
        vector<double> &m = m1;
        vector<double> &t = m2;
        double a = 0;
        // double b = 0;
        int    s = n;
        int mini = n;
        int maxi = n;
        m[n]=1.;
        bool cont=true;
        while (cont)
        {
            cont = false;
            s -= 4;
            for(int l=mini; l<=maxi; l++)
            {
                if (!m[l]) continue;
                 int    lb = s+(n-l);
                double f = m[l]/4;
                m[l] = 0;
                for(int i=1; i<=4; i++)
                {
                   // cout << l-25*i << ", " <<  lb+25*i  << endl;
                   if (c)
                   {
                        if      (l-1*i <0) {if (lb+1*i<0) {a+=f/2; }else  a+=f;}
                        else if (lb+1*i>= 0)  {t[l-1*i] = t[l-1*i]+f; cont = true;}
                   }
                   else
                  {
                        if      (l-1*i <=0) {if (lb+1*i<=0) {a+=f/2;}else  a+=f;}
                        else if (lb+1*i> 0)  {t[l-1*i] = t[l-1*i]+f; cont = true;}
                    }

                }
            }
            //if (a>.1-1e-5) return 1;
            swap(m,t);
            maxi-=1;
            if (mini>=4) mini -=4; else mini = 0;
        } 
        return a; 
    }
};