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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;

        ListNode* prev = sentinel;

        while(prev != NULL && prev->next != NULL){
            if(prev->next->val == val){
                prev->next = prev->next->next;
            }
            else{
                 prev = prev->next;
            }                    
        }
        return sentinel->next;
    }
};