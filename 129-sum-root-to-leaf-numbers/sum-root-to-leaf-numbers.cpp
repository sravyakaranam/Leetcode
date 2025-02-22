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
    int check(TreeNode* root,int su)
    {
        if(root==NULL)return 0;
        su=10*su+(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            return su;
        }
        int le=check(root->left,su);
        int ri=check(root->right,su);

        return le+ri;
    }
    int sumNumbers(TreeNode* root) {

        int res=0;
        return check(root,res);

        

        
    }
};