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
    int gs=0;
    void solvi(TreeNode* temp)
    {
        if(temp==NULL)return;
        solvi(temp->right);
        gs+=temp->val;
        temp->val=gs;

        solvi(temp->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        TreeNode* temp=root;
        solvi(temp);
        return temp;
    }

};