Approach-1: We first calculate longest common sequence in both the strings using dp. Then, subtract twice of lcs from sum of the length of two strings.
formula: M+N - 2*LCS
where- M-length of word1, N-length of word2
​
TC: O(MxN), SC: O(MxN)