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

    // Pattern 2-pointer approach (Slow & fast) (floyd's detection)
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {  //cycle exists
                isCycle = true; 
                break;
            }
        }

        if(!isCycle) {  //cycle does not exist
            return NULL;
        }   
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
        
        return slow;    //this is the meeting point
    }
};