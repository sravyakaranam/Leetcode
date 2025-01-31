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
    int maxLevelSum(TreeNode* root) {

        int maxi=INT_MIN;
        if(root==NULL)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int maxl=0;
        while(!q.empty())
        {
           int s=q.size();
           int su=0;
           level++;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                su+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
            }
            
             if(maxi<su)
             {
                maxi=su;
                maxl=level;
             }
            
        }
        return maxl;
        
    }
};