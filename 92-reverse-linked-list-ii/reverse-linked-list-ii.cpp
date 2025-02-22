/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==NULL || left==right)return head;
        ListNode* temp=new ListNode(0);
        temp->next=head;

        ListNode* prev=temp;

        for(int i=1;i<left;i++)
        {
            prev=prev->next;
        }

        ListNode* curr=prev->next;
        ListNode* nextt=NULL;
        ListNode* tempPrev=prev;

        for(int i=left;i<right;i++)
        {
            nextt=curr->next;
            curr->next=nextt->next;
            nextt->next=tempPrev->next;
            tempPrev->next=nextt;
        }
        return temp->next;
        
    }
};