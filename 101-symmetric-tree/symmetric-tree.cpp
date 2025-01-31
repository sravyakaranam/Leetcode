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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;

        return check(root->left,root->right);

        
    }
    bool check(TreeNode* a,TreeNode* b)
    {
        if(a==NULL && b==NULL)return true;
        if(a==NULL || b==NULL || a->val!=b->val)return false;
        return check(a->left,b->right)&&check(a->right,b->left);
    }
};