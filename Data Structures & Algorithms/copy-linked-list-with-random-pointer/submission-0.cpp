/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> map;
        
        //do one pass first
        Node dummy = Node(0);
        Node* curr_old = head;
        Node* curr_new = &dummy;
        while (curr_old != nullptr){
            curr_new->next = new Node(curr_old->val);
            curr_new = curr_new->next;
            map[curr_old] = curr_new; // Remember original -> copy
            curr_old = curr_old->next; 
        }

        //then do another pass for the randoms
        //doing it in one pass total is hard because you might point to an uncreated node
        curr_old = head;
        curr_new = dummy.next;
        while (curr_old != nullptr){
            if (curr_old->random != nullptr) {
                curr_new->random = map[curr_old->random];
            }
            curr_new = curr_new->next;
            curr_old = curr_old->next; 
        }

        return dummy.next;
    }
};
