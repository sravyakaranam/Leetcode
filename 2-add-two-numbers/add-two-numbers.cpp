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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL)return NULL;
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        int carry=0;
        while(l1&&l2)
        {
            int su=(l1->val)+(l2->val)+carry;
            cout<<su<<endl;
            carry=su/10;
            su=su%10;
            temp->next=new ListNode(su);
            
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1)
        {
            int su=carry+(l1->val);
            carry=su/10;
            su=su%10;
            temp->next=new ListNode(su);
            temp=temp->next;
            l1=l1->next;
        }
        while(l2)
        {
            int su=carry+(l2->val);
            carry=su/10;
            su=su%10;
            temp->next=new ListNode(su);
            temp=temp->next;
            l2=l2->next;
        }
        if(carry!=0){
            temp->next=new ListNode(carry);
        temp=temp->next;
        }
        
        return res->next;
    }
};