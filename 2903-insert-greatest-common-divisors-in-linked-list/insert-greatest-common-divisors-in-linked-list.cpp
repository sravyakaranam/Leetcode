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
    int gcd(int a,int b)
    {
        if(b==0)return a;
        else return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        
        if(head==NULL)return NULL;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }

        if(len==1)return head;

        ListNode* prev=head;
        ListNode* curr=head->next;

        while(prev && curr)
        {
            int a,b;
            if(prev->val < curr->val)
            {
                a=prev->val;
                b=curr->val;
            }
            else
            {
                a=curr->val;
                b=prev->val;
            }
            int re=gcd(a,b);
            ListNode* n=new ListNode(re);
            prev->next=n;
            n->next=curr;
            prev=curr;
            curr=curr->next;
        }
        cout<<len<<endl;
        return head;

    }
};