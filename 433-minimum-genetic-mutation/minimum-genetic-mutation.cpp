#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end()); // Convert bank to set for fast lookup
        if (geneBank.find(endGene) == geneBank.end()) return -1;  // If endGene is not in the bank, return -1

        queue<pair<string, int>> q;  // {current_gene, mutation_steps}
        unordered_set<string> visited;  // Track visited genes

        q.push({startGene, 0});
        visited.insert(startGene);

        vector<char> choices = {'A', 'C', 'G', 'T'}; // Possible mutations

        while (!q.empty()) {
            auto [currGene, steps] = q.front();
            q.pop();

            // If we reach the target gene, return the number of mutations
            if (currGene == endGene) return steps;

            // Try mutating each character in the gene
            for (int i = 0; i < currGene.size(); i++) {
                char originalChar = currGene[i];

                for (char c : choices) {
                    if (c == originalChar) continue;  // Skip same character

                    currGene[i] = c;  // Mutate gene
                    if (geneBank.count(currGene) && !visited.count(currGene)) { 
                        q.push({currGene, steps + 1});
                        visited.insert(currGene);
                    }
                }

                currGene[i] = originalChar;  // Restore original gene after testing
            }
        }

        return -1;  // If we exhaust all possibilities, return -1
    }
};
