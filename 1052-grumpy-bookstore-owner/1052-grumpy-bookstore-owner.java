class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
           
        int satisfied = 0; //without using extra minutes
        for(int i = 0; i<customers.length; i++)
        {
            if(grumpy[i] == 0) satisfied += customers[i];
        }
       
        //we  have a window of size "minutes"
        //we have to take maximum of all windows
        
        //first window;
        int curr = 0; //represents additional number of customers that can be satisfied;
        for(int i = 0; i<minutes; i++)
        {
            if(grumpy[i] == 1)
            {
                curr += customers[i];
            }
        }
        
        //remaining windows
        int max = curr+satisfied;
        for(int i = 1; i<=(customers.length-minutes); i++)
        {
           //subtracting i-1 th value if owner was grumpy
            if(grumpy[i-1] == 1)
            {
                curr -= customers[i-1];
            }
            
            //adding i+minutes+1 value if owner is grumpy
            if(grumpy[i+minutes-1] == 1)
            {
                curr += customers[i+minutes-1];
            }
            
             max = Math.max(max, curr+satisfied); // hence we have a next window;
        }
        return max;
    }
}