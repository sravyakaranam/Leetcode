/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void inorder(Node* root,Node* &prev,Node* &head)
    {
        if(!root)return;

        inorder(root->left,prev,head);

        if(!prev)
        {
            head=root;
        }
        else
        {
            prev->right=root;
            root->left=prev;
        }
        prev=root;

        inorder(root->right,prev,head);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root)return nullptr;

        Node* head=nullptr;
        Node* prev=nullptr;

        inorder(root,prev,head);

        head->left=prev;
        prev->right=head;

        return head;
        
    }

};