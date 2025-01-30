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
    int maxi=0;
    void check(TreeNode* root,int dir,int le)
    {
        if(root==NULL)return;
        maxi=max(maxi,le);
        if(dir==1)
        {
            check(root->left,0,le+1);
            check(root->right, 1, 1);
        }
        else if(dir==0)
        {
            check(root->left, 0, 1);
            check(root->right,1,le+1);
            
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL)return 0;
        check(root->left,0,1);
        check(root->right,1,1);

        return maxi;
        
    }
};