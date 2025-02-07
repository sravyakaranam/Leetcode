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
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        cout<<c<<endl;
        if(c==n)return head->next;
        ListNode* temp2=head;
        int re=c-n-1;
        while(re>0)
        {
            temp2=temp2->next;
            re--;
        }
        temp2->next=temp2->next->next;

        return head;
        
    }
};