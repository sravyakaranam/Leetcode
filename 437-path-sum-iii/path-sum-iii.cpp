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
    void check(TreeNode* root, long long int targetSum,int &res,long long int su)
    {
        if(root==NULL)return;
        su=su+(root->val);
        if(su==targetSum)
        {
            res++;
        }
        check(root->left,targetSum,res,su);
        check(root->right,targetSum,res,su);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        int res=0;
       
        check(root,(long long)targetSum,res,0);
        res+=pathSum(root->left,targetSum);
        res+=pathSum(root->right,targetSum);
        return res;
        
    }
};