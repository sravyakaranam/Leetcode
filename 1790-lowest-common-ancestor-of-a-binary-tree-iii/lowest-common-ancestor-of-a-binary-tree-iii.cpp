/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {

        
        Node* a=p;
        Node* b=q;

        while(a!=b)
        {
            if(a==NULL)a=q;
            else a=a->parent;

            if(b==NULL)b=p;
            else b=b->parent;
        }
        return a;
        
    }
};