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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int count{1};
        ListNode* dummy = head;
        while(dummy->next) {
            dummy = dummy->next;
            ++count;
        }

        // make LL circular
        dummy->next = head;

        // reduce k
        k %= count;

        // get new tail node
        ListNode* newTail = head;
        int steps = count - k - 1;
        while(steps > 0) {
            newTail = newTail->next;
            --steps;
        }

        // inlink new tail from new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};