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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        ListNode* curr=head;
        int co=0;
        while(curr!=NULL)
        {
            co+=1;
            curr=curr->next;
        }
        if(co==1 && n==1)return NULL;
        if(co==n && head->next)return head->next;
       cout<<co<<endl;
       int req=co-n;
       ListNode* temp=head;
       ListNode* prev=temp;
       while(req>0 && temp->next)
       {
           prev=temp;
           temp=temp->next;
           req--;
       }
        //delete temp;
       prev->next=temp->next;
        
       return head;
    }
};