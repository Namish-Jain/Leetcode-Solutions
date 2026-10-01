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
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head, *temp = nullptr;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool compareLists(ListNode* head1, ListNode* head2) {
        while(head1 && head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        // edge cases: list of size 0 and 1
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* temp = head;
        ListNode* mid = findMid(temp);
        ListNode* reverseHead = reverseList(mid);
        return compareLists(head, reverseHead);
    }
};