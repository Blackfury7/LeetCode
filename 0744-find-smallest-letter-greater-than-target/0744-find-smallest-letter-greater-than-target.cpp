class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        
        if(letters[n-1] <= target)
        return letters[0];

        for(int i=0;i<n;i++)
        {
            if(letters[i] > target)
            return letters[i];
        }

        return '1';
    }
};