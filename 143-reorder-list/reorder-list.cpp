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
    void reorderList(ListNode* head) {

    if (!head || !head->next || !head->next->next) return;

    
    ListNode* prev = nullptr;
    ListNode* last = head;
    while (last->next) {
        prev = last;
        last = last->next;
    }

    
    if (head->next != last) {
        prev->next = nullptr;  
        last->next = head->next;
        head->next = last;

       
        reorderList(last->next);
        

    }
    }
};