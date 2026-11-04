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
    bool hasCycle(ListNode* head) {
        unordered_set <ListNode*> set;
        ListNode* curr = head;

        while (curr != nullptr){
            if (set.count(curr) != 0){ //duplicate address found
                return true;
            }

            set.insert(curr);
            curr = curr->next;

        }

        return false;
    }
};
