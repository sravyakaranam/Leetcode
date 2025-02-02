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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        bool l=false;
        while(!q.empty())
        {
            int x=q.size();
            vector<int> s;
        
                for(int i=0;i<x;i++)
                {
                    TreeNode* temp=q.front();
                    q.pop();
                    s.push_back(temp->val);
                    
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                    
                }
            if(l==true)reverse(s.begin(),s.end());
            res.push_back(s);
            l=!l;
        }
        return res;
        
        
    }
};