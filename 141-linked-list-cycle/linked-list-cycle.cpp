/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Pattern :- Slow & Fast pointer approach (Floyd’s Cycle Detection)
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // move +1
            fast = fast->next->next; // move +2
            if (slow == fast) { //if slow == true it means there is a cycle
                return true;
            }
        }
        return false;   //there are no cycle 
    }
};