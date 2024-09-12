class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:

        temp=set(allowed)
        co=0
        for a in words:
            if set(a).issubset(temp):
                co=co+1

        return co
        