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
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
        bool res=false;
        queue<TreeNode*> q;
        q.push(root);
        int flagl=1;
        int flagr=1;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();

            cout<<temp->val<<endl;
            if(temp->left){if(res)return false;q.push(temp->left);}
            else res=true;

            if(temp->right){if(res)return false;q.push(temp->right);}
            else res=true;
        }
        //if(flagr && flagl==0)return false;
        //else if(flagr==0 && flagl==0)return true;

        return true;
    }
};