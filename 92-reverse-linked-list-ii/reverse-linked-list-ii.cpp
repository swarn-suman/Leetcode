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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        
        ListNode* left_prev = dummy;
        for (int i = 1; i < left; i++) {
            left_prev = left_prev->next;
        }

    
        ListNode* curr = left_prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = left_prev->next;
            left_prev->next = next;
        }
        return dummy->next;
    }
};