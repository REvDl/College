from collections import Counter

class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        counts = Counter(s)
        target_counts = Counter(target)
        if all(char in counts for char in target):
            min_element = float('inf')
            for char in target_counts:
                min_element = min(min_element, counts[char] // target_counts[char])
            return min_element
        return 0
