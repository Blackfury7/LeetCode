Solution 2  (Two-Pointer, One-Pass)
​
We are required to remove the nth node from the end of list. For this, we need to traverse N - n nodes from the start of the list, where N is the length of linked list. We can do this in one-pass as follows -
​
Let's assign two pointers - fast and slow to head. We will first iterate for n nodes from start using the fast pointer.
​
Now, between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node (which currently is fast).