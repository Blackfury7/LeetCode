class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        count = reduce(operator.or_, (Counter(b) for b in words2))
        return [a for a in words1 if count & Counter(a) == count]
        