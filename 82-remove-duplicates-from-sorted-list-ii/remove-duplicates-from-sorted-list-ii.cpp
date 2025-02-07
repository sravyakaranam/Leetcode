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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return NULL;

        
        unordered_map<int,int> mp;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            
            mp[temp->val]++;
            temp=temp->next;

        }

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;

        while(curr!=NULL)
        {
            if(mp[curr->val]==1)
            {
                
                prev=curr;
            }
            else if(mp[curr->val]>1)
            {
                prev->next=curr->next;
            }
            curr=curr->next;
        }
        
        

        return dummy->next;
    }
};