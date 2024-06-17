class Solution {
public:
    bool judgeSquareSum(int c) {

        long long l = 0;
        long long r = sqrt(c); 

        while (l <= r) {
            long long ls = l * l;
            long long rs = r * r;
            if (ls + rs == c) {
                return true; 
            } else if (ls + rs > c) {
                r--; 
            } else {
                l++; 
            }
        }
        return false; 
    }
};