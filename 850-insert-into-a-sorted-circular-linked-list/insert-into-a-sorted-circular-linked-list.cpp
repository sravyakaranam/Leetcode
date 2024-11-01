/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        Node* temp=head;
        Node* valu=new Node(insertVal);
        if(!head)
        {
            valu->next=valu;
            
            return valu;
        }
        while(true)
        {
            if(temp->val <= insertVal && temp->next->val>=insertVal)
            {
                break;
            }
            if(temp->val>temp->next->val)
            {
                if(temp->val <= insertVal || temp->next->val>=insertVal)
                {
                    break;
                }
            }
            temp=temp->next;
            if(temp==head)
            {
                break;
            }
        }
        valu->next=temp->next;
        temp->next=valu;

        return head;
        
    }
};