from collections import defaultdict
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:

        substring_count= defaultdict(int)
        
        n=len(s)

        for i in range(minSize,maxSize+1):
            for j in range(n-i+1):
                substr=s[j:j+i]
                if len(set(substr))<=maxLetters:
                    substring_count[substr]+=1

        return max(substring_count.values(),default=0)

        