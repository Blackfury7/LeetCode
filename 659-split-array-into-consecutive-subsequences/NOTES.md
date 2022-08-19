**Greedy algorithm**:
left is a hashmap, left[i] counts the number of i that hasn't placed yet.
end is a hashmap, end[i] counts the number of consecutive subsequences that ends at number i
Then splitting the nums one by one.
If its not possible to add a number to the end of a existing consecutive subsequence or find two following number in the left, I returned False
​
​
​
**Note**: The key point of this solution is If there is a valid subsequence ended with x-1, place current x at the end of subsequence always better/less risk than create a new subsequence started with x due to has length at least 3.
​
**Complexity**
Time O(N)
Space O(N)