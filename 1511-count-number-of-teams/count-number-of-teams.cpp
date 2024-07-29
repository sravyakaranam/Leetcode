#include <vector>

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;

        // Loop through each soldier as the potential middle of the team
        for (int j = 0; j < n; ++j) {
            int lessLeft = 0, moreLeft = 0;
            int lessRight = 0, moreRight = 0;

            // Count soldiers on the left of j
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) lessLeft++;
                if (rating[i] > rating[j]) moreLeft++;
            }

            // Count soldiers on the right of j
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) lessRight++;
                if (rating[k] > rating[j]) moreRight++;
            }

            // Calculate the number of valid teams where j is the middle soldier
            result += lessLeft * moreRight + moreLeft * lessRight;
        }

        return result;
    }
};
