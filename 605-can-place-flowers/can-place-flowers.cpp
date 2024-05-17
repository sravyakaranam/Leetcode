class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0; // To count valid placements
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if current spot is empty and both adjacent spots are either empty or non-existent
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1; // Plant a flower here
                count++; // Increment count of flowers planted
                if (count >= n) return true; // Check if we have planted enough flowers
            }
        }
        return n <= count; // Check if we were able to plant at least 'n' flowers
        
    }
};