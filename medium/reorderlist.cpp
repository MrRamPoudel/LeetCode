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
    void reorderList(ListNode* head) {
        if(!head) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Now the slow->next will contain the second half of the list, sever the list and reverse second half
        auto second = slow->next;
        //sever the list
        slow->next = nullptr;
        //reverse the second list now
        ListNode* prev = nullptr;
        while (second ){
            auto temp =second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
    
        //now that the second list is reversed, merge it
        ListNode * first = head;
        second = prev;
        while(second) {
            auto temp1 = first->next;
            auto temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
