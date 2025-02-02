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
    int maxSum = INT_MIN; // Global variable to store max path sum

    int findMaxPath(TreeNode* root) {
        if (root == NULL) return 0; // Base case: No contribution from NULL nodes

        // Recursively get max path sum from left and right subtrees
        int leftSum = max(0, findMaxPath(root->left));  // Ignore negative sums
        int rightSum = max(0, findMaxPath(root->right));

        // Calculate the maximum path sum **including both left and right subtrees**
        int currentMax = root->val + leftSum + rightSum;

        // Update global maxSum
        maxSum = max(maxSum, currentMax);

        // Return the maximum single-path sum (choose left or right)
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return maxSum;
    }
};