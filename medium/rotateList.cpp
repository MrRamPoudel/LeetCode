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
 //use mod when k> length of list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k ==0 || !head || !head->next) {
            return head;
        }
        auto temp = head;
        int count = 0;
        while(temp) {
            temp = temp->next;
            ++count;
        }
        k = k % count; 
        while(k>0) {
           auto  left = head;
           auto   right = head->next;
           temp = nullptr;
            while(right && right->next) {
                temp = left;
                left = right;
                right = right->next;
            }
            //update head here
            right->next = head;
            left->next = nullptr;
            --k;
            head = right;
        }
        return head;
    }
};
