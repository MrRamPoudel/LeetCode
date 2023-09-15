/*
    Use a two pointers, one is fast one is slow
    keep the fast pointer nth step ahead of slow
    remove slow pointer->next
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fast = head;
        auto slow = head;
        for (int i = 0; i<n; ++i) {
            fast = fast->next;
        }
        auto temp = head;
        if(!fast) {
            head = head->next;
            delete temp;
            return head;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};