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

        TreeNode* helper(TreeNode* node, vector<TreeNode*>& forest, unordered_set<int>& toDeleteSet) {
            if (!node) return nullptr;

            
            node->left = helper(node->left, forest, toDeleteSet);
            node->right = helper(node->right, forest, toDeleteSet);

          
            if (toDeleteSet.count(node->val)) {
               
                if (node->left) forest.push_back(node->left);
                if (node->right) forest.push_back(node->right);
                return nullptr;  
            }
            return node;  
        }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
       

       
        if (!toDeleteSet.count(root->val)) {
            forest.push_back(root);
        }
        helper(root, forest, toDeleteSet);

        return forest;
        
    }
};