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
    vector<int> getout(vector<int> res)
    {
        if (res.size() < 2) return {-1, -1}; 
        vector<int> out;
        int mini=INT_MAX;
        for(int i=1;i<res.size();i++)
        {
            mini=min(mini,res[i]-res[i-1]);
        }
        out.push_back(mini);
        out.push_back(res[res.size()-1]-res[0]);

        return out;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res;
        vector<int> out(2,-1);
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Nextt;
        int co=0;
        while(curr->next!=NULL)
        {
            co++;
            Nextt=curr->next;
            if(prev!=NULL){
            if((curr->val > Nextt->val && curr->val > prev->val) || (curr->val < Nextt->val && curr->val < prev->val)) 
            {
                res.push_back(co);
            }
            }
            prev=curr;
            curr=curr->next;
        }
        cout<<co<<endl;
        if(res.empty()) return {-1,-1};
        else return getout(res);
    }
};