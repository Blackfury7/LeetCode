Greedy Approach:
It's better explained through an example. Let's say the target is 'aabccbc', and stamp is 'abc'. We first try to find 'abc' and replace it with '***'. After there are no more replacements, we will try '*bc' and 'ab*', and so on. Now, turn by turn:
​
'aabccbc' ? 'abc' = [1]
'a***cbc' ? '*bc' = []
'a***cbc' ? 'ab*' = []
'a***cbc' ? 'a**' = [0]
'****cbc' ? '*b*' = []
'****cbc' ? '**c' = [2]
'*****bc' ? '*bc' = [4]