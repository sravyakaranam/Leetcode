class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] will store the minimum height to place first i books
        dp[0] = 0; // No books, no height

        for (int i = 1; i <= n; i++) {
            int width = 0;
            int height = 0;
            // Try to place books[j] to books[i-1] on the same shelf
            for (int j = i; j > 0; j--) {
                width += books[j-1][0];
                if (width > shelfWidth) break; // Cannot add more books on this shelf
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }

        return dp[n];
    }
};
