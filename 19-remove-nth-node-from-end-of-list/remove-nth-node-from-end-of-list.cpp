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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);

        ListNode* sentinel = new ListNode();
        sentinel->next = head;

        ListNode* prev = sentinel;
        int index = 1;

        while(prev != NULL && prev->next != NULL){
            if(index == length-n+1){
                prev->next = prev->next->next;
                break;
            }
            else{
                 prev = prev->next;
                 index++;
            }                    
        }
        return sentinel->next;
    }
};