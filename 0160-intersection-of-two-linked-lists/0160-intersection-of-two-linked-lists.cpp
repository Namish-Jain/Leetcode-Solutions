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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* list1 = headA;
        ListNode* list2 = headB;

        while(list1 != list2) {
            if (list1) list1 = list1->next;
            else list1 = headB;
            if (list2) list2 = list2->next;
            else list2 = headA;
        }
        return list1;
    }
};