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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int curr = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            curr++;
        }

        k = k % curr;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* before = dummy;
        ListNode* after = dummy;
        while(k != 0){
            after = after->next;
            k--;
        }

        while(after != NULL && after->next != NULL){
            after = after->next;
            before = before->next;
        }
        after->next = dummy->next;
        dummy->next = before->next;
        before->next = NULL;

        return dummy->next;
    }
};