class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(0);
        ListNode* curr3 = &dummy;

        int digit = 0;
        int carry = 0;

        // Continue while either list has nodes or a carry remains
        while (curr1 != nullptr || curr2 != nullptr || carry != 0) {

            // Treat missing nodes as 0
            int digit1 = 0;
            if (curr1 != nullptr){
                digit1 = curr1->val;
            }
            int digit2 = 0;
            if (curr2 != nullptr){
                digit2 = curr2->val;
            }

            // Add both digits and the carry from the previous iteration
            digit = digit1 + digit2 + carry;

            // Store the ones digit and calculate the next carry
            curr3->next = new ListNode(digit % 10);
            carry = digit / 10;

            // Advance pointers only if they aren't nullptr
            if (curr1 != nullptr) {
                curr1 = curr1->next;
            }
            if (curr2 != nullptr) {
                curr2 = curr2->next;
            }

            curr3 = curr3->next;
        }

        return dummy.next;
    }
};