Intuition
For the first number, it could be any number from 1 to k.
So my intuition is to check the first occurrence of all number from 1 to k.
​
Complexity
Time O(n)
Space O(k)
​
​
Explanation
We check the first occurrences of all number from A[0].
Assume A[i] is the rightmost one among them,
which is the first occurrence of a number in [1,k].
​
That means from A[0] to A[i],
we have seen all numbers at least once.
In other words, A[0] to A[i] forms our first complete set including all numbers.
​
This complete set can satisfy any number from 1 to k,
as the first number in the sequence.
​
Then we continue this process, to find out the next complete set.
We continue doing this, and assume we can find x complete sets in total.
There may ramian some elements, but the rest can not form one more set of all numebr.
​
Then we can take any sequence of length x,
x + 1 is the length of the shortest sequence of rolls,
that cannot be taken from rolls.