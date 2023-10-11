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
 //Use dummy node to swap pointers
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        auto dummy = new ListNode();
        dummy->next = head;

        ListNode * right = head;
        ListNode * left = dummy;
       
        //swap left and right, increment right and left
        while(right && right->next) {
           left->next = right->next;
           right->next = left->next->next;
           left->next->next = right;
           left = right;
           right = right->next;
        }
        head = dummy->next;
        delete dummy;
        return head;

    }
};