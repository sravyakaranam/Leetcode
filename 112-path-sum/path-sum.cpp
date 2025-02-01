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
    void check(TreeNode* root,int su,int target,bool &t)
    {
        if(root==NULL)return;
        su=su+(root->val);
        if(root->left==NULL && root->right==NULL)
        {if(su==target)t=true;
        return;
        }
        
        
        check(root->left,su,target,t);
        check(root->right,su,target,t);
        
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL)return false;
        bool t=false;
        check(root,0,targetSum,t);
        return t;
    }
};