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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* curr=head->next;
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        int su=0;
        while(curr!=NULL)
        {
            if(curr->val!=0)
            {
                su=su+curr->val;    
            }
            else
            {
                cout<<su<<endl;
                //res=ListNode(su);
                
                temp->next=new ListNode(su);
                temp=temp->next;
                //res->next=temp;
                //res=res->next;
                su=0;
            }
            curr=curr->next;
            
        }
       // res=temp;
    return res->next;

        
    }
};