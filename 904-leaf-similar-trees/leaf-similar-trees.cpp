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
    void forma(TreeNode* root1,vector<int> &a)
    {
       if (root1 == NULL) return;
        if(root1->left==NULL && root1->right==NULL)
        {
            a.push_back(root1->val);
            return;
        }
        forma(root1->left,a);
        forma(root1->right,a);

    }
    void formb(TreeNode* root2,vector<int> &b)
    {
        if (root2 == NULL) return;
        if(root2->left==NULL && root2->right==NULL)
        {
            b.push_back(root2->val);
            return;
        }
        formb(root2->left,b);
        formb(root2->right,b);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)return true;
        vector<int> a;
        forma(root1,a);
        vector<int> b;
        formb(root2,b);

        if(a==b)return true;
        else return false;

        
        
    }
};