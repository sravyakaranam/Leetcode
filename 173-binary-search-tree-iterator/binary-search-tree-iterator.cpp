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
#include <stack>

class BSTIterator {
    stack<TreeNode*> st; // Stack to store nodes

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root); // Initialize by pushing all left nodes
    }
    
    int next() {
        if (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            int value = node->val;
            
            // If there is a right subtree, push its leftmost nodes
            if (node->right) {
                pushLeft(node->right);
            }
            
            return value;
        }
        return -1; // Should not reach here in valid calls
    }
    
    bool hasNext() {
        return !st.empty(); // If stack is not empty, we have next element
    }

private:
    // Pushes all left children onto the stack
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */