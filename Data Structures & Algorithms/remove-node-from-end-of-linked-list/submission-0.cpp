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
        
        ListNode* curr = head;
        int size = 0;
        int counter = 0;

        //determine size of linkedlist
        while (curr != nullptr){
            curr = curr->next;
            size++;
        }

        //start from beginning
        curr = head;

        if (size == n){
            head = curr->next;
            return head;
        }

        while (curr != nullptr && counter < (size-n)-1){
            curr = curr->next;
            counter++;
        }
        curr->next = curr->next->next;

        return head;
    }
};
