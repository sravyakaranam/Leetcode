/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countGoodNodes(TreeNode* root, int maxSoFar) {
        if (root == NULL) return 0;

        // Check if the current node is a "good node"
        int count = (root->val >= maxSoFar) ? 1 : 0;

        // Update the max value for the next recursive calls
        maxSoFar = max(maxSoFar, root->val);

        // Recursively check left and right subtrees
        return count + countGoodNodes(root->left, maxSoFar) + countGoodNodes(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);  // Start with the root node value as the max
    }
};
