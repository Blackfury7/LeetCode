class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxf = 0, i = 0, n = answerKey.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[answerKey[j] - 'A']);
            if (j - i + 1 > maxf + k)
                --count[answerKey[i++] - 'A'];
        }
        return n - i;      
    }
};