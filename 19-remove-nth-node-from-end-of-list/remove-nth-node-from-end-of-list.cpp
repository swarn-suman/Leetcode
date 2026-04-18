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
        ListNode* look = new ListNode();
        look->next = head;

        ListNode* prev = look;
        ListNode* after = look;

        while(n != 0){
            after = after->next;
            n--;
        }

        while(after != NULL && after->next != NULL){
            after = after->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return look->next;
    }
};