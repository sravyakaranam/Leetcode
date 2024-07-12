class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if y > x:
            up, high, down, low = 'ba', y, 'ab', x
        else:
            up, high, down, low = 'ab', x, 'ba', y
        
        def remove_pairs(s: str, pair: str, points: int) -> (str, int):
            stack = []
            score = 0
            for char in s:
                if stack and stack[-1] == pair[0] and char == pair[1]:
                    stack.pop()
                    score += points
                else:
                    stack.append(char)
            return ''.join(stack), score
        
        s, score1 = remove_pairs(s, up, high)
        s, score2 = remove_pairs(s, down, low)
        
        return score1 + score2
        