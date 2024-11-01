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
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;  // If the tree is empty, return nullptr
        
        Node* head = nullptr;  // Head of the doubly linked list
        Node* prev = nullptr;  // Previous node to link to
        
        inorder(root, prev, head);
        
        // Connect the head and tail to make it circular
        head->left = prev;
        prev->right = head;
        
        return head;
    }
    
private:
    void inorder(Node* node, Node*& prev, Node*& head) {
        if (!node) return;
        
        // Inorder traversal: Process the left subtree
        inorder(node->left, prev, head);
        
        // Process the current node
        if (!prev) {
            // This is the first (smallest) node, set it as the head
            head = node;
        } else {
            // Link the current node with the previous node
            prev->right = node;
            node->left = prev;
        }
        
        // Move `prev` to `node` for the next iteration
        prev = node;
        
        // Inorder traversal: Process the right subtree
        inorder(node->right, prev, head);
    }
};
