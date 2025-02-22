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
    TreeNode* build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>& iMap)
    {
        if(prestart>preend || instart>inend)return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);

        int iRoot=iMap[root->val];
        int nleft=iRoot-instart;

        root->left=build(preorder,prestart+1,prestart+nleft,inorder,instart,iRoot-1,iMap);
        root->right=build(preorder,prestart+nleft+1,preend,inorder,iRoot+1,inend,iMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> iMap;
        for(int i=0;i<inorder.size();i++)
        {
            iMap[inorder[i]]=i;
        }
        TreeNode* res=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,iMap);
        return res;
        
    }
};