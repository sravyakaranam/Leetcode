/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

       if(head==NULL||head->next==NULL)return false;
        ListNode* curr=head;
        ListNode* prev=head;

        while(prev && prev->next)
        {

            
            curr=curr->next;
            prev=prev->next->next;
            if(curr==prev)return true;
        }
        
      return false;

        
    }
};