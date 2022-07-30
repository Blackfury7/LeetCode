class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        count = Counter()
        for b in words2:
            count |= Counter(b)
        return [a for a in words1 if not count - Counter(a)]
        