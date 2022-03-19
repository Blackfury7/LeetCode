**Algo**
​
0. We will take a variable max_frequency which indicate the maximum number of ocurrence.
​
1. We will consider a frequency map that will count the occurences of each element.
​
2. We will also consider a map group_stack which will group the elements with the same frequecy. Example if two elements have same count then we will add them in stack with the recent element at the top.
​
3. When we will push the elements
a. We will increment its frequency
b. Update the maximum occurence element
c. group the element with its frequency
​
4. When we will pop the element from stack
a. We will take out the max_frequency element.
b. Remove it from group_stack
c. Decrement its freuency
d. Return it