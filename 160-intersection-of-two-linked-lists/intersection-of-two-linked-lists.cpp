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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode* a = headA;
        ListNode* b = headB;
        int cnt = 0;

        while (cnt < 2) {
            if (a == b)
                return a;

            if (a != NULL) {
                a = a->next;
            } else {
                a = headB;
                cnt++;
            }

            if (b != NULL) {
                b = b->next;

            } else {
                b = headA;
            }
        }
        return NULL;
    }
};