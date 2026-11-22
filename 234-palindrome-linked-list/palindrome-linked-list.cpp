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
    //Pattern :-> Slow & Fast + Classical Reversed LL + two pointer
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        //find middle
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse Right Half Part
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* currNext = NULL;
        
        while(curr != NULL) {
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }

        ListNode* st = head;
        ListNode* end = prev;

        while(st < end) {
            if(st->val != end->val) return false;
            st = st->next;
            end = end->next;
        }
        return true;
    }
};